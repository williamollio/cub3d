/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:45:21 by wollio            #+#    #+#             */
/*   Updated: 2022/04/05 18:45:31 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	ft_lst_data_count(t_map_data *head)
{
	t_map_data	*tmp;
	int			count;

	if (!head)
		return (-1);
	tmp = head;
	count = 0;
	while (tmp->next)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}

t_map_data	*ft_data_new_data(char *string)
{
	t_map_data	*lstnew;

	lstnew = (t_map_data *)xmalloc(sizeof(t_map_data));
	lstnew->next = NULL;
	lstnew->data = string;
	return (lstnew);
}

void	ft_data_append_data(t_map_data **lst, t_map_data *new)
{
	t_map_data	*tmp;

	tmp = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_map	*ft_lstnew(void)
{
	t_map	*lstnew;

	lstnew = (t_map *)xmalloc(sizeof(t_map));
	lstnew->next = NULL;
	lstnew->prev = NULL;
	return (lstnew);
}

void	ft_lstadd_back(t_map **lst, t_map *new)
{
	t_map	*tmp;

	tmp = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}
