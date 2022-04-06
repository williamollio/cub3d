/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:48:25 by wollio            #+#    #+#             */
/*   Updated: 2022/04/05 18:49:29 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	check_wall_before(t_vars *data, double x, double y)
{
	t_map	*tmp;

	tmp = data->t_map;
	while (tmp)
	{
		if ((tmp->y == y - 1) && (tmp->x == x + 1))
		{
			if (tmp->o != '1')
				return (1);
			while (tmp->next && tmp->y == tmp->next->y)
			{
				if (tmp->next->o != '1')
					return (1);
				tmp = tmp->next;
			}
		}
		tmp = tmp->next;
	}
	return (0);
}

int	get_length_line(t_map *node)
{
	t_map	*line;
	int		length;

	line = node;
	length = 0;
	while (line && line->x != 0)
		line = line->prev;
	while (line && line->y == node->y)
	{
		length++;
		line = line->next;
	}
	return (length - 1);
}

int	get_length_previous_line(t_map *node)
{
	t_map	*tmp;

	tmp = node;
	while (tmp)
	{
		if (tmp->y == node->y - 1)
			return (get_length_line(tmp));
		tmp = tmp->prev;
	}
	return (-1);
}

int	check_up(t_map *node)
{
	t_map	*tmp;
	int		prev;

	prev = 1;
	tmp = node;
	while (tmp)
	{
		if (tmp->x == node->x && tmp->y == node->y - prev)
		{
			if (is_space_tab(tmp->o))
				prev++;
			else if (tmp->o != '1')
				return (1);
			else if (tmp->o == '1')
				break ;
		}
		tmp = tmp->prev;
	}
	return (0);
}

int	check_down(t_map *node)
{
	t_map	*tmp;
	int		next;

	next = 0;
	tmp = node;
	while (tmp)
	{
		if (tmp->x == node->x && tmp->y == node->y + next)
		{
			if (is_space_tab(tmp->o))
				next++;
			else if (tmp->o != '1')
				return (1);
			else if (tmp->o == '1')
				break ;
		}
		tmp = tmp->next;
	}
	return (0);
}
