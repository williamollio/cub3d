/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:44:17 by wollio            #+#    #+#             */
/*   Updated: 2022/04/06 18:10:14 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

t_vars	*get_data(int fd)
{
	t_vars	*data;
	char	*read;

	data = (t_vars *)xmalloc(sizeof(t_vars));
	init_location(data);
	get_next_line(fd, &read);
	get_data_2(data, &read, fd);
	data->map_done = is_map_valid(data);
	build_2d_charmap(data);
	if ((data->id_done == false || data->map_done == false) && clear_data(data))
		return (NULL);
	return (data);
}

t_vars	*check_file_content(char *file)
{
	int		fd;
	t_vars	*data;

	fd = open(file, O_RDONLY);
	data = NULL;
	if (fd < 0)
		error("Error : corrupted file (open)");
	data = get_data(fd);
	if (data == NULL)
		error("Error : misconfiguration");
	if (close(fd) == -1)
	{
		clear_data(data);
		error("Corrupted file (close)");
	}
	return (data);
}

int	check_file_format(char *file_name)
{
	int			len;
	const char	*start;

	len = ft_strlen(file_name);
	if (len <= 4)
		return (1);
	start = (const char *) &file_name[(len - 4)];
	if (ft_strncmp(start, ".cub", 4) == 0)
		return (0);
	return (1);
}
