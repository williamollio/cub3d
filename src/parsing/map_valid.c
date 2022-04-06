/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:48:19 by wollio            #+#    #+#             */
/*   Updated: 2022/04/05 18:49:13 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	check_surrounded(t_map *node, t_vars *data)
{
	if (check_left(node))
		return (1);
	if (check_right(node))
		return (1);
	if (node->y != (data->i - 1) && check_down(node))
		return (1);
	if (node->y != 0 && check_up(node))
		return (1);
	return (0);
}

bool	map_valid_body(t_vars *data, t_map *node, int *n_col, bool *player_set)
{
	if (node->o == '0' && node->x > get_length_previous_line(node))
		return (false);
	if (is_space_tab(node->o) && check_surrounded(node, data))
		return (false);
	if (ft_single_inset(node->o, "01NSEW") == -1 && !is_space_tab(node->o))
		return (false);
	if (ft_single_inset(node->o, "NSEW") != -1)
	{
		if (*player_set)
			return (false);
		*player_set = true;
	}
	if (node->next != NULL && node->y != node->next->y)
		*n_col = node->x;
	if ((node->y == 0 && node->o != '1' && node->o != ' ')
		|| (node->y == (data->i - 1) && node->o == '0'))
		return (false);
	if ((node->x == 0 && node->o != '1' && node->o != ' ') || (node->next
			&& node->y != node->next->y && node->o != '1'))
		return (false);
	if ((node->next != NULL && node->y != node->next->y)
		&& check_wall_before(data, node->x, node->y))
		return (false);
	return (true);
}

bool	is_map_valid(t_vars *data)
{
	t_map	*node;
	bool	player_set;
	int		n_col;

	node = data->t_map;
	player_set = false;
	n_col = 0;
	while (node)
	{
		if (map_valid_body(data, node, &n_col, &player_set) == false)
			return (false);
		node = node->next;
	}
	return (player_set);
}
