/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_content_utils2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiliamollio <wiliamollio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:48:13 by wollio            #+#    #+#             */
/*   Updated: 2022/04/19 11:44:51 by wiliamollio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	fill_path(char **path, char *read)
{
	int		i;

	i = 0;
	while (read[i] == ' ')
		i++;
	if (read[i] != '\0')
		*path = ft_strdup(&read[i]);
}

static void	check_rgb(char **arr)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (ft_atoi(arr[i]) < 0 || ft_atoi(arr[i]) > 255)
			error("error : rgb invalid");
		i++;
	}
	return ;
}

void	fill_rgb(long *color, char *read)
{
	int		i;
	char	**arr;

	i = 0;
	while (read[i] == ' ')
		i++;
	if (ft_isdigit(read[i]) == 0)
		return ;
	arr = ft_split(&read[i], ',');
	if (arr == NULL)
		return ;
	if (!arr[0] || !arr[1] || !arr[2])
	{
		ft_memfreeall((void **)arr);
		return ;
	}
	check_rgb(arr);
	*color = (65536 * ft_atoi(arr[0])) + (256 * ft_atoi(arr[1]))
		+ ft_atoi(arr[2]);
	ft_memfreeall((void **)arr);
}
