/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:33:03 by wollio            #+#    #+#             */
/*   Updated: 2022/04/05 19:33:23 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*xmalloc(size_t size)
{
	void	*dest;

	if (size == 0)
		return (NULL);
	dest = malloc(size);
	if (!dest)
		exit(0);
	return (dest);
}
