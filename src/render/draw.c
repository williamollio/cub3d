/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:19:46 by agunczer          #+#    #+#             */
/*   Updated: 2022/04/05 19:19:47 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	draw(t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	while (y < vars->win_height)
	{
		x = 0;
		while (x < vars->win_width)
		{
			vars->addr[y * (int)vars->win_width + x] = vars->tex->buff[y][x];
			x++;
		}
		y++;
	}
	minimap(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}
