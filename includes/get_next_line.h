/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:03:54 by wollio            #+#    #+#             */
/*   Updated: 2022/04/06 12:09:45 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

# define MAXFD			4096
# define BUFFER_SIZE	10000

char		*ft_strjoin_dif(char const *s1, char const *s2);
char		*ft_strdup_dif(const char *s1);
char		*ft_substr_dif(char const *s, unsigned int start, size_t len);
int			get_next_line(int fd, char **line);

#endif