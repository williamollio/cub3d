/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:21:54 by agunczer          #+#    #+#             */
/*   Updated: 2022/04/06 12:01:08 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	load_image(t_vars *vars, int *texture, char *path)
{
	t_imgTemp	t;

	t.img = mlx_xpm_file_to_image(vars->mlx, path, &t.img_width, &t.img_height);
	if (t.img == NULL)
		error("Error : loading map");
	t.addr = (int *)mlx_get_data_addr(t.img, &t.bits_per_pixel,
			&t.line_length, &t.endian);
	t.y = 0;
	while (t.y < t.img_height)
	{
		t.x = 0;
		while (t.x < t.img_width)
		{
			texture[t.img_width * t.y + t.x] = t.addr[t.img_width * t.y + t.x];
			t.x++;
		}
		t.y++;
	}
	mlx_destroy_image(vars->mlx, t.img);
}

void	load_texture(t_vars *vars)
{
	load_image(vars, vars->tex->texture[0], vars->north);
	load_image(vars, vars->tex->texture[1], vars->south);
	load_image(vars, vars->tex->texture[2], vars->west);
	load_image(vars, vars->tex->texture[3], vars->east);
}

void	choose_texture_for_pixel(t_vars *vars)
{
	if (vars->calc->side == 0 && vars->calc->raydir_x < 0)
	{
		vars->tex->texcolor
			= vars->tex->texture[0][64 * vars->tex->texy + vars->tex->texx];
	}
	else if (vars->calc->side == 0 && vars->calc->raydir_x >= 0)
	{
		vars->tex->texcolor
			= vars->tex->texture[1][64 * vars->tex->texy + vars->tex->texx];
	}
	if (vars->calc->side == 1 && vars->calc->raydir_y < 0)
	{
		vars->tex->texcolor
			= vars->tex->texture[2][64 * vars->tex->texy + vars->tex->texx];
	}
	else if (vars->calc->side == 1 && vars->calc->raydir_y >= 0)
	{
		vars->tex->texcolor
			= vars->tex->texture[3][64 * vars->tex->texy + vars->tex->texx];
	}
}

/*
1.	Cast the texture coordinate to integer,
	and mask with (texHeight - 1) in case of overflow
2.	get color for pixel, depending on the texture we currently look at
3.	texture we use for walls depends on the direction we are looking at
- do color darker for y-sides
- write pixel to buffer
*/
void	write_pixels_to_buffer(t_vars *vars, int x, int y)
{
	while (y < vars->calc->draw_end)
	{
		vars->tex->texy = (int)vars->tex->texpos & (64 - 1);
		vars->tex->texpos += vars->tex->step;
		choose_texture_for_pixel(vars);
		if (vars->calc->side == 1)
			vars->tex->texcolor = (vars->tex->texcolor >> 1) & 8355711;
		vars->tex->buff[y][x] = vars->tex->texcolor;
		y++;
	}
}

/*
- wallx = value where the wall was hit.
- texx = x coordinate on the texture
- step =  increase of the texture coordinate per screen pixel
- texpos = starting texture coordinate
*/
void	draw_texture(t_vars *vars, int x)
{
	int	y;

	if (vars->calc->side == 0)
	{
		vars->tex->wallx
			= vars->calc->pos_y + vars->calc->wall_dist * vars->calc->raydir_y;
	}
	else
	{
		vars->tex->wallx
			= vars->calc->pos_x + vars->calc->wall_dist * vars->calc->raydir_x;
	}
	vars->tex->wallx -= floor(vars->tex->wallx);
	vars->tex->texx = (int)(vars->tex->wallx * ((double)64));
	if (vars->calc->side == 0 && vars->calc->raydir_x > 0)
		vars->tex->texx = 64 - vars->tex->texx - 1;
	if (vars->calc->side == 1 && vars->calc->raydir_y < 0)
		vars->tex->texx = 64 - vars->tex->texx - 1;
	vars->tex->step = 1.0 * 64 / vars->calc->line_height;
	vars->tex->texpos = (vars->calc->draw_start - vars->win_height
			/ 2 + vars->calc->line_height / 2) * vars->tex->step;
	y = vars->calc->draw_start;
	write_pixels_to_buffer(vars, x, y);
}
