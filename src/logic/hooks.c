/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:36:13 by wollio            #+#    #+#             */
/*   Updated: 2022/04/06 17:12:25 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	closewindow(t_vars *vars)
{
	ft_free(vars);
	exit(0);
}

int	setkeyflagfalse(int keycode, t_vars *vars)
{
	mlx_do_key_autorepeatoff(vars->mlx);
	if (keycode == 1)
		vars->key->downflag = false;
	if (keycode == 2)
		vars->key->rightflag = false;
	if (keycode == 0)
		vars->key->leftflag = false;
	if (keycode == 13)
		vars->key->upflag = false;
	if (keycode == 124)
		vars->key->arrowleftflag = false;
	if (keycode == 123)
		vars->key->arrowrightflag = false;
	return (1);
}

int	setkeyflagtrue(int keycode, t_vars *vars)
{
	mlx_do_key_autorepeaton(vars->mlx);
	if (keycode == 1)
		vars->key->downflag = true;
	if (keycode == 2)
		vars->key->rightflag = true;
	if (keycode == 0)
		vars->key->leftflag = true;
	if (keycode == 13)
		vars->key->upflag = true;
	if (keycode == 124)
		vars->key->arrowleftflag = true;
	if (keycode == 123)
		vars->key->arrowrightflag = true;
	if (keycode == 53)
		closewindow(vars);
	return (1);
}
