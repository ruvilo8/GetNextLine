/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolo <lolo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:55:27 by lolo              #+#    #+#             */
/*   Updated: 2023/11/09 16:05:55 by lolo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);

int		fill_in_buffer(char **buffer, int fd);
int		ft_strchr(char *str, char c);
char	*ft_strjoin(char **s1, char const *s2);
char	*ft_strdup(const char *src);
char	*ft_fstrdup(char **fsrc, const char *src);

#endif
