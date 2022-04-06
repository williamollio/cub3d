/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:19:55 by agunczer          #+#    #+#             */
/*   Updated: 2022/04/06 11:52:27 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static void	reset_counters(t_vars *vars)
{
	vars->minimap->a = 0;
	vars->minimap->b = 0;
	vars->minimap->u = 0;
	vars->minimap->o = 0;
	vars->minimap->pa = 0;
	vars->minimap->pb = 0;
}

static void	render_minimap(t_vars *vars, int color, int pixels_to_draw)
{
	vars->minimap->pb = vars->minimap->b * pixels_to_draw;
	vars->minimap->o = 0;
	while (vars->minimap->o < pixels_to_draw - 1)
	{
		vars->addr[vars->minimap->pa
			* (int)vars->win_width + vars->minimap->pb] = color;
		vars->minimap->pb++;
		vars->minimap->o++;
	}
}

static void	setup_draw(t_vars *vars, int pixels_to_draw)
{
	char	c;

	c = vars->map[vars->minimap->a][vars->minimap->b];
	if (c == '1')
		render_minimap(vars, 0x00F0F0F0, pixels_to_draw);
	else if (c == '0' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W')
		render_minimap(vars, 0x00000000, pixels_to_draw);
	if ((vars->minimap->a == (int)vars->calc->pos_x)
		&& (vars->minimap->b == (int)vars->calc->pos_y))
		render_minimap(vars, 0x00FF0000, pixels_to_draw);
}

void	minimap(t_vars *vars)
{
	int	pixels_to_draw;

	pixels_to_draw = 10;
	reset_counters(vars);
	while (vars->map[vars->minimap->a])
	{
		vars->minimap->b = 0;
		while (vars->map[vars->minimap->a][vars->minimap->b])
		{
			vars->minimap->u = 0;
			vars->minimap->pa = vars->minimap->a * pixels_to_draw;
			while (vars->minimap->u < pixels_to_draw - 1)
			{
				setup_draw(vars, pixels_to_draw);
				vars->minimap->u++;
				vars->minimap->pa++;
			}
			vars->minimap->b++;
		}
		vars->minimap->a++;
	}
}
