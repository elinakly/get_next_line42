/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklymova <eklymova@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:57:33 by eklymova          #+#    #+#             */
/*   Updated: 2024/12/04 23:24:14 by eklymova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_str(int fd, char *s)
{
	char		*buff;
	ssize_t		bytes;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	bytes = BUFFER_SIZE;
	while ((!ft_strchr(s, '\n')) && bytes > 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1 || (!bytes && s[0] == '\0'))
			return (free(buff), NULL);
		buff[bytes] = '\0';
		s = ft_strjoin(s, buff);
		if (!s)
			return (free(buff), NULL);
	}
	return (free(buff), s);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*s = NULL;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!s)
	{
		s = malloc(1);
		if (!s)
			return (free(s), s = NULL, NULL);
		s[0] = '\0';
	}
	temp = read_str(fd, s);
	if (!temp)
		return (free(s), s = NULL, NULL);
	s = temp;
	line = get_n_line(s);
	if (!line)
		return (free(s), s = NULL, NULL);
	s = new_string(s);
	if (!s)
		return (free(line), line = NULL, NULL);
	return (line);
}
