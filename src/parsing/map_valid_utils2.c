/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:48:30 by wollio            #+#    #+#             */
/*   Updated: 2022/04/05 18:49:18 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	is_space_tab(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	ft_single_inset(char c, char const *set)
{
	int	count;

	count = 0;
	while (set[count])
	{
		if (c == set[count])
			return (count);
		count++;
	}
	return (-1);
}

int	check_right(t_map *node)
{
	t_map	*tmp;

	tmp = node;
	while (tmp && is_space_tab(tmp->o))
		tmp = tmp->next;
	if (tmp->o != '1')
		return (1);
	return (0);
}

int	check_left(t_map *node)
{
	t_map	*tmp;

	tmp = node;
	while (tmp->prev && is_space_tab(tmp->o))
		tmp = tmp->prev;
	if (tmp->y == node->y && tmp->o != '1' && tmp->prev != NULL)
		return (1);
	return (0);
}
