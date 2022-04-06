/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:19:04 by agunczer          #+#    #+#             */
/*   Updated: 2022/04/06 11:55:01 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static int	player2(char c, t_math *calc)
{
	if (c == 'N')
	{
		calc->dir_x = -1.00;
		calc->dir_y = 0.00;
		calc->plane_x = 0;
		calc->plane_y = 0.66;
		return (1);
	}
	else if (c == 'S')
	{
		calc->dir_x = 1.00;
		calc->dir_y = 0.00;
		calc->plane_x = 0;
		calc->plane_y = -0.66;
		return (1);
	}
	return (0);
}

static int	player(char c, t_math *calc)
{
	if (c == 'W')
	{
		calc->dir_x = 0.00;
		calc->dir_y = -1.00;
		calc->plane_x = -0.66;
		calc->plane_y = 0;
		return (1);
	}
	else if (c == 'E')
	{
		calc->dir_x = 0.00;
		calc->dir_y = 1.00;
		calc->plane_x = 0.66;
		calc->plane_y = 0;
		return (1);
	}
	else if (player2(c, calc))
		return (1);
	return (0);
}

static void	player_pos(t_vars *data, t_math *calc)
{
	int			y;
	int			x;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (player(data->map[x][y], calc))
			{
				calc->pos_x = (double)x + 0.5;
				calc->pos_y = (double)y + 0.5;
				calc->playerdir = data->map[x][y];
			}
			if (y > calc->max_y)
				calc->max_y = y;
			y++;
		}
		if (x > calc->max_x)
			calc->max_x = x;
		x++;
	}
}

t_math	*init_calc(t_vars *data)
{
	t_math	*re;

	re = malloc(sizeof(t_math));
	re->max_x = 0;
	re->max_y = 0;
	player_pos(data, re);
	re->time = 0;
	re->old_time = 0;
	return (re);
}
