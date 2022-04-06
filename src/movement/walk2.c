/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:19:39 by agunczer          #+#    #+#             */
/*   Updated: 2022/04/06 11:58:37 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static void	setpos_wmove(t_vars *vars)
{
	double	x;

	x = vars->calc->pos_y - vars->calc->plane_y * vars->calc->move_speed;
	if ((vars->map[(int)(vars->calc->pos_x + 0.2)][(int)(x + 0.2)] != '1')
	&& (vars->map[(int)(vars->calc->pos_x + 0.2)][(int)(x - 0.2)] != '1')
	&& (vars->map[(int)(vars->calc->pos_x + 0.2)][(int)(x)] != '1')
	&& (vars->map[(int)(vars->calc->pos_x)][(int)(x + 0.2)] != '1')
	&& (vars->map[(int)(vars->calc->pos_x)][(int)(x - 0.2)] != '1')
	&& (vars->map[(int)(vars->calc->pos_x - 0.2)][(int)(x + 0.2)] != '1')
	&& (vars->map[(int)(vars->calc->pos_x - 0.2)][(int)(x)] != '1')
	&& (vars->map[(int)(vars->calc->pos_x - 0.2)][(int)(x - 0.2)] != '1'))
		vars->calc->pos_y -= vars->calc->plane_y * vars->calc->move_speed;
}

void	walk_west(t_vars *vars)
{
	double	i;

	i = vars->calc->pos_x - vars->calc->plane_x * vars->calc->move_speed;
	if ((vars->map[(int)(i + 0.2)][(int)(vars->calc->pos_y + 0.2)] != '1')
	&& (vars->map[(int)(i + 0.2)][(int)(vars->calc->pos_y)] != '1')
	&& (vars->map[(int)(i + 0.2)][(int)(vars->calc->pos_y - 0.2)] != '1')
	&& (vars->map[(int)(i)][(int)(vars->calc->pos_y + 0.2)] != '1')
	&& (vars->map[(int)(i)][(int)(vars->calc->pos_y - 0.2)] != '1')
	&& (vars->map[(int)(i - 0.2)][(int)(vars->calc->pos_y - 0.2)] != '1')
	&& (vars->map[(int)(i - 0.2)][(int)(vars->calc->pos_y + 0.2)] != '1')
	&& (vars->map[(int)(i - 0.2)][(int)(vars->calc->pos_y)] != '1'))
		vars->calc->pos_x -= vars->calc->plane_x * vars->calc->move_speed;
	setpos_wmove(vars);
}

static void	setpos_nmove(t_vars *vars)
{
	double	x;

	x = vars->calc->pos_y + vars->calc->dir_y * vars->calc->move_speed;
	if ((vars->map[(int)(vars->calc->pos_x - 0.2)][(int)(x + 0.2)] != '1')
	&& (vars->map[(int)(vars->calc->pos_x - 0.2)][(int)(x - 0.2)] != '1')
	&& (vars->map[(int)(vars->calc->pos_x - 0.2)][(int)(x)] != '1')
	&& (vars->map[(int)(vars->calc->pos_x + 0.2)][(int)(x + 0.2)] != '1')
	&& (vars->map[(int)(vars->calc->pos_x + 0.2)][(int)(x - 0.2)] != '1')
	&& (vars->map[(int)(vars->calc->pos_x + 0.2)][(int)(x)] != '1')
	&& (vars->map[(int)(vars->calc->pos_x)][(int)(x + 0.2)] != '1')
	&& (vars->map[(int)(vars->calc->pos_x)][(int)(x - 0.2)] != '1'))
		vars->calc->pos_y += vars->calc->dir_y * vars->calc->move_speed;
}

void	walk_nord(t_vars *vars)
{
	double	i;

	i = vars->calc->pos_x + vars->calc->dir_x * vars->calc->move_speed;
	if ((vars->map[(int)(i + 0.2)][(int)(vars->calc->pos_y - 0.2)] != '1')
	&& (vars->map[(int)(i + 0.2)][(int)(vars->calc->pos_y)] != '1')
	&& (vars->map[(int)(i + 0.2)][(int)(vars->calc->pos_y + 0.2)] != '1')
	&& (vars->map[(int)(i - 0.2)][(int)(vars->calc->pos_y + 0.2)] != '1')
	&& (vars->map[(int)(i - 0.2)][(int)(vars->calc->pos_y - 0.2)] != '1')
	&& (vars->map[(int)(i - 0.2)][(int)(vars->calc->pos_y)] != '1')
	&& (vars->map[(int)(i)][(int)(vars->calc->pos_y + 0.2)] != '1')
	&& (vars->map[(int)(i)][(int)(vars->calc->pos_y - 0.2)] != '1'))
		vars->calc->pos_x += vars->calc->dir_x * vars->calc->move_speed;
	setpos_nmove(vars);
}
