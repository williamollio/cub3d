/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceilling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:19:51 by agunczer          #+#    #+#             */
/*   Updated: 2022/04/06 11:58:06 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	set_ceiling_floor(t_vars *vars, int x)
{
	int	u;
	int	z;

	u = 0;
	while (u < vars->calc->draw_start)
	{
		vars->tex->buff[u][x] = vars->ceillingcode;
		u++;
	}
	z = vars->calc->draw_end;
	while (z < vars->win_height)
	{
		vars->tex->buff[z][x] = vars->floorcode;
		z++;
	}
}
