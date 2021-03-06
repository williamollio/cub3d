/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 17:09:06 by wollio            #+#    #+#             */
/*   Updated: 2021/08/03 11:18:42 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (0);
	while (src[i])
		i++;
	if (dstsize == 0)
		return (i);
	while (*src && dstsize--)
		*dst++ = *src++;
	*dst = '\0';
	return (i);
}

// int main()
// {
// 	char *dst;
// 	char *src;

// 	dst = ft_strdup("test");
// 	src = ft_strdup("reussi");
// 	ft_strlcpy(dst, src, ft_strlen(src));
// 	printf("%s", dst);
// }