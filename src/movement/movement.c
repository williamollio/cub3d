/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiliamollio <wiliamollio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:19:27 by agunczer          #+#    #+#             */
/*   Updated: 2022/04/19 12:04:54 by wiliamollio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	rightward_rotation(t_vars *vars)
{
	vars->calc->olddir_x = vars->calc->dir_x;
	vars->calc->dir_x = vars->calc->dir_x * cos(vars->calc->rot_speed)
		- vars->calc->dir_y * sin(vars->calc->rot_speed);
	vars->calc->dir_y = vars->calc->olddir_x * sin(vars->calc->rot_speed)
		+ vars->calc->dir_y * cos(vars->calc->rot_speed);
	vars->calc->oldplane_x = vars->calc->plane_x;
	vars->calc->plane_x = vars->calc->plane_x * cos(vars->calc->rot_speed)
		- vars->calc->plane_y * sin(vars->calc->rot_speed);
	vars->calc->plane_y = vars->calc->oldplane_x * sin(vars->calc->rot_speed)
		+ vars->calc->plane_y * cos(vars->calc->rot_speed);
}

void	leftward_rotation(t_vars *vars)
{
	vars->calc->olddir_x = vars->calc->dir_x;
	vars->calc->dir_x = vars->calc->dir_x * cos(-vars->calc->rot_speed)
		- vars->calc->dir_y * sin(-vars->calc->rot_speed);
	vars->calc->dir_y = vars->calc->olddir_x * sin(-vars->calc->rot_speed)
		+ vars->calc->dir_y * cos(-vars->calc->rot_speed);
	vars->calc->oldplane_x = vars->calc->plane_x;
	vars->calc->plane_x = vars->calc->plane_x * cos(-vars->calc->rot_speed)
		- vars->calc->plane_y * sin(-vars->calc->rot_speed);
	vars->calc->plane_y = vars->calc->oldplane_x * sin(-vars->calc->rot_speed)
		+ vars->calc->plane_y * cos(-vars->calc->rot_speed);
}

static void	walk(t_vars *vars)
{
	if (vars->key->downflag == true)
		walk_south(vars);
	if (vars->key->rightflag == true)
		walk_east(vars);
	if (vars->key->leftflag == true)
		walk_west(vars);
	if (vars->key->upflag == true)
		walk_nord(vars);
}

void	movement(t_vars *vars)
{
	walk(vars);
	if (vars->key->arrowrightflag == true)
		rightward_rotation(vars);
	if (vars->key->arrowleftflag == true)
		leftward_rotation(vars);
}
