/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolo <lolo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:44:13 by lolo              #+#    #+#             */
/*   Updated: 2023/11/09 20:34:39 by lolo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	fill_in_buffer(char **buffer, int fd)
{
	char	*buff;
	int		i;

	buff = malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff || fd < 0 || BUFFER_SIZE < 1)
	{
		free(buff);
		return (0);
	}
	if (*buffer == NULL)
		*buffer = ft_strdup("");
	buff[0] = 0;
	while (ft_strchr(buff, '\n') == -1)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i <= 0)
			break ;
		buff[i] = 0;
		*buffer = ft_strjoin(buffer, buff);
	}
	free(buff);
	if (i < 0)
		return (0);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			enter;

	if (!fill_in_buffer(&buffer, fd))
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	enter = ft_strchr(buffer, '\n');
	if (enter >= 0)
	{
		line = ft_strdup(buffer);
		line[enter + 1] = 0;
		buffer = ft_fstrdup(&buffer, &buffer[enter + 1]);
		return (ft_fstrdup(&line, line));
	}
	if (buffer[0] == 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	return (ft_fstrdup(&buffer, buffer));
}
