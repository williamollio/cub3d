/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 09:16:19 by wollio            #+#    #+#             */
/*   Updated: 2022/04/05 19:35:48 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

static char	*ft_next_line(char *rprogress, char **line, int *result_int)
{
	int		i;
	char	*temp;

	i = 0;
	while (rprogress[i] && (rprogress[i] != '\n'))
		i++;
	*line = ft_substr_dif(rprogress, 0, i);
	if (rprogress[i] == '\n')
	{
		temp = ft_strdup_dif(rprogress + i + 1);
		free(rprogress);
		rprogress = temp;
		*result_int = 1;
		if (rprogress[0] == '\0')
		{
			free(rprogress);
			rprogress = NULL;
		}
		return (rprogress);
	}
	*result_int = 0;
	free(rprogress);
	rprogress = NULL;
	return (rprogress);
}

int	ft_return_zero_emptystring(char **line)
{
	*line = ft_strdup_dif("");
	return (0);
}

void	ft_set_rprogress(char **rprogress, char *buffer)
{
	if (!*rprogress)
		*rprogress = ft_strdup_dif(buffer);
	else
		*rprogress = ft_strjoin_dif(*rprogress, buffer);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	if (s[i] == c)
		return (((char *)s) + i);
	return (NULL);
}

int	get_next_line(int fd, char **line)
{
	static char	*rprogress[MAXFD];
	int			result_int;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if ((!line) || (!(buffer)))
		return (-1);
	result_int = read(fd, buffer, BUFFER_SIZE);
	while (result_int > 0)
	{
		buffer[result_int] = '\0';
		ft_set_rprogress(&rprogress[fd], buffer);
		if (ft_strchr(rprogress[fd], '\n'))
			break ;
		result_int = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if ((result_int == 0 && !rprogress[fd]))
		return (ft_return_zero_emptystring(line));
	if (result_int < 0)
		return (-1);
	rprogress[fd] = ft_next_line(rprogress[fd], line, &result_int);
	return (result_int);
}
