/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:48:06 by wollio            #+#    #+#             */
/*   Updated: 2022/04/06 14:20:14 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <stdbool.h>
# include <stdlib.h>
# include "get_next_line.h"

# define WIDTH 1680
# define HEIGHT 1200

typedef struct s_map {
	double			x;
	double			y;
	char			o;
	struct s_map	*next;
	struct s_map	*prev;
}	t_map;

typedef struct s_map_data {
	char				*data;
	struct s_map_data	*next;
}	t_map_data;

typedef struct s_imgTemp
{
	int		img_width;
	int		img_height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*img;
	int		*addr;
	int		y;
	int		x;
}				t_imgTemp;

typedef struct s_math
{
	char		playerdir;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		time;
	double		old_time;
	double		camera_x;
	double		raydir_x;
	double		raydir_y;

	int			map_x;
	int			max_x;
	int			map_y;
	int			max_y;

	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		wall_dist;

	double		step_x;
	double		step_y;
	double		hit;
	double		side;
	double		line_height;
	double		draw_start;
	double		draw_end;

	double		frame_time;
	double		move_speed;
	double		rot_speed;
	double		olddir_x;
	double		oldplane_x;
}				t_math;

typedef struct s_key
{
	bool	upflag;
	bool	downflag;
	bool	leftflag;
	bool	rightflag;
	bool	arrowleftflag;
	bool	arrowrightflag;
}				t_key;

typedef struct s_minimap
{
	int	a;
	int	b;
	int	pa;
	int	pb;
	int	o;
	int	u;
}				t_minimap;

typedef struct s_texture
{
	int			buff[HEIGHT][WIDTH];
	int			**texture;
	double		wallx;
	int			texx;
	double		step;
	double		texpos;
	int			texy;
	int			texcolor;
}				t_tex;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	long		floorcode;
	long		ceillingcode;
	char		**map;
	double		win_width;
	double		win_height;
	void		*img;
	void		*img_tex;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_key		*key;
	t_math		*calc;
	t_minimap	*minimap;
	t_tex		*tex;
	t_map_data	*map_data;
	t_map		*t_map;
	bool		map_done;
	bool		id_done;
	int			i;
}				t_vars;

/* Initialization struct */
void		initDataStructure(t_vars *data);
t_math		*init_calc(t_vars *data);
void		init_minimap(t_vars *data);
t_key		*init_key(t_vars *data);
t_tex		*init_texture(t_vars *data);
void		init_location(t_vars *re);
void		initdatastructure(t_vars *data);

/* Key capture */
int			setkeyflagtrue(int keycode, t_vars *vars);
int			setkeyflagfalse(int keycode, t_vars *vars);
int			closewindow(t_vars *vars);

/* Raycasting */
void		raypositionanddirection(t_vars *vars, int x);
void		stepandsidedistance(t_vars *vars);
void		ddaalgorithm(t_vars *vars);
void		drawatartanddraw_end(t_vars *vars);

/* Render */
void		ft_mlx_init(t_vars *data);
void		game_start(t_vars *data);
int			logic(t_vars *vars);
void		draw(t_vars *vars);
void		set_ceiling_floor(t_vars *vars, int x);
void		minimap(t_vars *vars);
void		draw_texture(t_vars *vars, int x);
void		load_texture(t_vars *vars);

/* Movements */
void		movement(t_vars *vars);
void		walk_south(t_vars *vars);
void		walk_east(t_vars *vars);
void		walk_west(t_vars *vars);
void		walk_nord(t_vars *vars);

/* Tool */
void		error(char *str);
void		*xmalloc(size_t size);
t_map_data	*ft_data_new_data(char *string);
void		ft_data_append_data(t_map_data **lst, t_map_data *new);
int			ft_memfreeall(void **ptr);
int			ft_memfree(void *ptr);
t_map		*ft_lstnew(void);
void		ft_lstadd_back(t_map **lst, t_map *new);
int			ft_lst_data_count(t_map_data *head);
void		ft_free(t_vars *data);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_joinstr(char **arr);

/* Parsing */
int			check_file_format(char *file_name);
t_vars		*check_file_content(char *file);
t_vars		*get_data(int fd);
void		get_data_2(t_vars *data, char **read, int fd);
int			identifier(t_vars *data, char *read);
int			map(t_vars *data, char *read);
void		map_body(t_vars **data, t_map *tmp, char *str);
void		identifier_done(t_vars *data);
bool		is_map_valid(t_vars *data);
bool		map_valid_body(t_vars *data, t_map *node,
				int *n_col, bool *player_set);
int			ft_single_inset(char c, char const *set);
int			check_wall_before(t_vars *data, double x, double y);
int			clear_data(t_vars *cub);
int			check_up(t_map *node);
int			check_down(t_map *node);
int			check_left(t_map *node);
int			check_right(t_map *node);
int			check_surrounded(t_map *node, t_vars *data);
void		build_2d_charmap(t_vars *data);
void		fill_rgb(long *color, char *read);
void		fill_path(char **path, char *read);
int			is_space_tab(char c);
int			get_length_previous_line(t_map *node);
int			get_length_line(t_map *node);

#endif
