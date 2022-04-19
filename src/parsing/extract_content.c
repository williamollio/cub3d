/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_content.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiliamollio <wiliamollio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:07:34 by wollio            #+#    #+#             */
/*   Updated: 2022/04/19 11:49:30 by wiliamollio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	identifier(t_vars *data, char *read)
{
	if (read[0] == 'N' && read[1] == 'O' && read[2] == ' '
		&& data->north == NULL)
		fill_path(&data->north, &read[2]);
	else if (read[0] == 'S' && read[1] == 'O' && read[2] == ' '
		&& data->south == NULL)
		fill_path(&data->south, &read[2]);
	else if (read[0] == 'W' && read[1] == 'E' && read[2] == ' '
		&& data->west == NULL)
		fill_path(&data->west, &read[2]);
	else if (read[0] == 'E' && read[1] == 'A' && read[2] == ' '
		&& data->east == NULL)
		fill_path(&data->east, &read[2]);
	else if (read[0] == 'F' && read[1] == ' ' && data->floorcode == -1)
		fill_rgb(&data->floorcode, &read[1]);
	else if (read[0] == 'C' && read[1] == ' ' && data->ceillingcode == -1)
		fill_rgb(&data->ceillingcode, &read[1]);
	else
		return (1);
	return (0);
}

void	map_body(t_vars **data, t_map *tmp, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		tmp = ft_lstnew();
		tmp->x = i;
		tmp->y = (*data)->i;
		tmp->o = str[i];
		ft_lstadd_back(&(*data)->t_map, tmp);
		i++;
	}
	free(str);
}

int	map(t_vars *data, char *read)
{
	t_map				*tmp;
	char				**arr;
	char				*str;
	static t_map_data	*map_data = NULL;

	tmp = NULL;
	arr = ft_split(read, '\n');
	if (arr == NULL)
		return (1);
	str = ft_joinstr(arr);
	if (str == NULL)
		return (1);
	if (!map_data)
		map_data = ft_data_new_data(ft_strdup(read));
	else
		ft_data_append_data(&map_data, ft_data_new_data(ft_strdup(read)));
	ft_memfreeall((void **)arr);
	map_body(&data, tmp, str);
	data->i += 1;
	data->map_data = map_data;
	return (0);
}

void	build_2d_charmap(t_vars *data)
{
	t_map_data	*t_map_data;
	int			count;

	t_map_data = data->map_data;
	count = ft_lst_data_count(data->map_data);
	data->map = xmalloc((sizeof(char *) * (count + 2)));
	count = 0;
	while (t_map_data)
	{
		data->map[count] = t_map_data->data;
		t_map_data = t_map_data->next;
		count++;
	}
	data->map[count] = NULL;
}

void	get_data_2(t_vars *data, char **read, int fd)
{
	while (read != NULL)
	{
		if (ft_strcmp(*read, "\0") == 0)
		{
			if (data->t_map != NULL)
			{
				free(*read);
				break ;
			}
		}
		else if (data->id_done == false && identifier(data, *read))
			error("Error : identifier");
		else if (data->id_done == true && map(data, *read))
			error("Error : map");
		identifier_done(data);
		free(*read);
		get_next_line(fd, read);
	}
}
