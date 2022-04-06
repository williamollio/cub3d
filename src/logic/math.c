/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:36:30 by wollio            #+#    #+#             */
/*   Updated: 2022/04/06 12:01:08 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

/*
1.	calculate ray position and direction
2.	camera_x = x-coordinate on the camera plane,
	that represents the current x-coordinate of the screen
3.	rayDir = Direction of the current ray
4.	map_x, Y = which box of the map, the current ray is in
5.	deltaDist = length of ray from one x or y-side to next x or y-side
*/
void	raypositionanddirection(t_vars *vars, int x)
{
	vars->calc->camera_x = 2 * x / vars->win_width - 1;
	vars->calc->raydir_x
		= vars->calc->dir_x + vars->calc->plane_x * vars->calc->camera_x;
	vars->calc->raydir_y
		= vars->calc->dir_y + vars->calc->plane_y * vars->calc->camera_x;
	vars->calc->map_x = (int)vars->calc->pos_x;
	vars->calc->map_y = (int)vars->calc->pos_y;
	if (vars->calc->raydir_x == 0)
		vars->calc->delta_dist_x = 1e30;
	else
		vars->calc->delta_dist_x = fabs(1 / vars->calc->raydir_x);
	if (vars->calc->raydir_y == 0)
		vars->calc->delta_dist_y = 1e30;
	else
		vars->calc->delta_dist_y = fabs(1 / vars->calc->raydir_y);
}

/*
1.	step = what direction to step in x or y-direction (either +1 or -1)
2.	sideDist = length of ray from current position to next x or y-side
*/
void	stepandsidedistance(t_vars *vars)
{
	if (vars->calc->raydir_x < 0)
	{
		vars->calc->step_x = -1;
		vars->calc->side_dist_x = (vars->calc->pos_x - vars->calc->map_x)
			* vars->calc->delta_dist_x;
	}
	else
	{
		vars->calc->step_x = 1;
		vars->calc->side_dist_x = (vars->calc->map_x + 1.0 - vars->calc->pos_x)
			* vars->calc->delta_dist_x;
	}
	if (vars->calc->raydir_y < 0)
	{
		vars->calc->step_y = -1;
		vars->calc->side_dist_y = (vars->calc->pos_y - vars->calc->map_y)
			* vars->calc->delta_dist_y;
	}
	else
	{
		vars->calc->step_y = 1;
		vars->calc->side_dist_y = (vars->calc->map_y + 1.0 - vars->calc->pos_y)
			* vars->calc->delta_dist_y;
	}
}

static void	ddahitcheck(t_vars *vars)
{
	if (!(vars->calc->map_x < vars->calc->max_x && vars->calc->map_x >= 0))
		vars->calc->hit = 1;
	if (!(vars->calc->map_y < vars->calc->max_y && vars->calc->map_y >= 0))
		vars->calc->hit = 1;
	if (vars->map[vars->calc->map_x][vars->calc->map_y] == '1')
		vars->calc->hit = 1;
}

/*
1.	jump to next map square, either in x-direction, or in y-direction
2.	hit = was there a wall hit? (ray hit a wall)
3.	side = was a NS or a EW wall hit? (which side of the wall)
*/
void	ddaalgorithm(t_vars *vars)
{
	vars->calc->hit = 0;
	while (vars->calc->hit == 0)
	{
		if (vars->calc->side_dist_x < vars->calc->side_dist_y)
		{
			vars->calc->side_dist_x += vars->calc->delta_dist_x;
			vars->calc->map_x += vars->calc->step_x;
			vars->calc->side = 0;
		}
		else
		{
			vars->calc->side_dist_y += vars->calc->delta_dist_y;
			vars->calc->map_y += vars->calc->step_y;
			vars->calc->side = 1;
		}
		if (vars->calc->map_x < 0)
			vars->calc->map_x = vars->calc->map_x * -1;
		if (vars->calc->map_y < 0)
			vars->calc->map_y = vars->calc->map_y * -1;
		ddahitcheck(vars);
	}
}

/*
1.	Calculate distance from player to wall (wall_dist)
2.	Calculate height of line to draw on screen (line_height)
3.	side = was a NS or a EW wall hit? (which side of the wall)
4.	calculate lowest and highest pixel to fill in current stripe (drawS/E)
*/
void	drawatartanddraw_end(t_vars *vars)
{
	if (vars->calc->side == 0)
		vars->calc->wall_dist
			= (vars->calc->side_dist_x - vars->calc->delta_dist_x);
	else
		vars->calc->wall_dist
			= (vars->calc->side_dist_y - vars->calc->delta_dist_y);
	vars->calc->line_height
		= (int)(vars->win_height / vars->calc->wall_dist);
	vars->calc->draw_start
		= -vars->calc->line_height / 2 + (int)vars->win_height / 2;
	if (vars->calc->draw_start < 0)
		vars->calc->draw_start = 0;
	vars->calc->draw_end
		= vars->calc->line_height / 2 + (int)vars->win_height / 2;
	if (vars->calc->draw_end >= (int)vars->win_height)
		vars->calc->draw_end = (int)vars->win_height - 1;
}
