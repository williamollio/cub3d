/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:18:49 by agunczer          #+#    #+#             */
/*   Updated: 2022/04/12 13:53:31 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	free_list_t_map(t_map *node)
{
	t_map	*tmp;

	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
}

void	free_list(t_map_data *node)
{
	t_map_data	*tmp;

	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
}

void	ft_free(t_vars *data)
{
	int	i;

	i = 0;
	free(data->north);
	free(data->south);
	free(data->east);
	free(data->west);
	free(data->calc);
	free(data->key);
	free(data->minimap);
	while (i < 5)
	{
		free(data->tex->texture[i]);
		i++;
	}
	free(data->tex->texture);
	free(data->tex);
	free_list_t_map(data->t_map);
	free_list(data->map_data);
	ft_memfreeall((void **)data->map);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	free(data);
	exit (1);
}
