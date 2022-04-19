/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiliamollio <wiliamollio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:36:39 by wollio            #+#    #+#             */
/*   Updated: 2022/04/19 12:01:16 by wiliamollio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	logic(t_vars *vars)
{
	int	x;

	x = 0;
	movement(vars);
	while (x < (int)vars->win_width)
	{
		raypositionanddirection(vars, x);
		stepandsidedistance(vars);
		ddaalgorithm(vars);
		drawatartanddraw_end(vars);
		draw_texture(vars, x);
		set_ceiling_floor(vars, x);
		x++;
	}
	draw(vars);
	return (1);
}

void	ft_mlx_init(t_vars *data)
{
	data->mlx = mlx_init();
	load_texture(data);
	data->win = mlx_new_window(data->mlx, data->win_width,
			data->win_height, "CUB3D");
	data->calc->frame_time = (16) / 1000.0;
	data->calc->move_speed = data->calc->frame_time * 5.0;
	data->calc->rot_speed = data->calc->frame_time * 3.0;
	data->img = mlx_new_image(data->mlx, data->win_width, data->win_width);
	data->addr = (int *)mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
}

void	initdatastructure(t_vars *data)
{
	data->calc = init_calc(data);
	if (data->calc == NULL)
		error("Error : initialization struct math");
	data->key = init_key(data);
	if (data->key == NULL)
		error("Error : initialization struct key");
	data->tex = init_texture(data);
	if (data->tex == NULL)
		error("Error : initialization struct tex");
	init_minimap(data);
	if (data->minimap == NULL)
		error("Error : initialization struct minimap");
	return ;
}

void	game_start(t_vars *data)
{
	mlx_do_key_autorepeatoff(data->mlx);
	mlx_hook(data->win, 17, (1L << 17), closewindow, &data);
	mlx_hook(data->win, 2, (1L << 0), &setkeyflagtrue, data);
	mlx_hook(data->win, 3, (1L << 1), &setkeyflagfalse, data);
	mlx_loop_hook(data->mlx, logic, data);
	mlx_loop(data->mlx);
}
