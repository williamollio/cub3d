/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:48:37 by wollio            #+#    #+#             */
/*   Updated: 2022/04/05 18:49:21 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

char	*ft_joinstr(char **arr)
{
	char	*tmp;
	char	*buf;
	int		i;

	i = 1;
	if (arr[0] == NULL)
		return (NULL);
	buf = ft_strdup(arr[0]);
	while (arr[i] != NULL)
	{
		tmp = ft_strjoin(buf, arr[i]);
		free(buf);
		buf = tmp;
		i++;
	}
	return (buf);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (-1);
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char) s2[i]);
}

int	ft_memfree(void *ptr)
{
	if (ptr == NULL)
		return (1);
	free(ptr);
	ptr = NULL;
	return (1);
}

int	ft_memfreeall(void **ptr)
{
	int	i;

	i = 0;
	if (ptr == NULL)
		return (1);
	while (ptr[i] != NULL)
	{
		ft_memfree(ptr[i]);
		i++;
	}
	free(ptr);
	ptr = NULL;
	return (1);
}

int	clear_data(t_vars *cub)
{
	t_map		*to_free;
	t_map		*tmp;
	t_map_data	*data_tmp;
	t_map_data	*data_tofree;

	to_free = cub->t_map;
	while (to_free != NULL)
	{
		tmp = to_free->next;
		free(to_free);
		to_free = tmp;
	}
	data_tofree = cub->map_data;
	while (to_free != NULL)
	{
		data_tmp = data_tofree->next;
		free(data_tofree);
		data_tofree = data_tmp;
	}
	return (1);
}
