/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_content_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:07:45 by wollio            #+#    #+#             */
/*   Updated: 2022/04/06 17:25:32 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	init_location(t_vars *data)
{
	data->win_width = WIDTH;
	data->win_height = HEIGHT;
	data->floorcode = -1;
	data->ceillingcode = -1;
	data->north = NULL;
	data->south = NULL;
	data->west = NULL;
	data->east = NULL;
	data->id_done = false;
	data->map_done = false;
	data->i = 0;
}

void	identifier_done(t_vars *data)
{
	if (data->north == NULL)
		return ;
	if (data->south == NULL)
		return ;
	if (data->west == NULL)
		return ;
	if (data->east == NULL)
		return ;
	if (data->floorcode < 0)
		return ;
	if (data->ceillingcode < 0)
		return ;
	data->id_done = true;
}
