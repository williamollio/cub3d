/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiliamollio <wiliamollio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 08:22:03 by wollio            #+#    #+#             */
/*   Updated: 2022/04/19 11:22:21 by wiliamollio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_overlap(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (src + i == dst)
			return (0);
		i++;
	}
	return (1);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	(void)i;
	i = 0;
	if (!dst && !src)
		return (NULL);
	if (check_overlap(dst, src, len))
		return (ft_memcpy(dst, src, len));
	else
	{
		while (len)
		{
			((char *)dst)[len - 1] = ((char *)src)[len - 1];
			len--;
		}
		return (dst);
	}
}
