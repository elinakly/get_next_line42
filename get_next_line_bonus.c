/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklymova <eklymova@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:11:27 by eklymova          #+#    #+#             */
/*   Updated: 2024/12/04 23:28:23 by eklymova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_str(char *s, int fd)
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
	static char	*s[1024];
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	if (!s[fd])
	{
		s[fd] = malloc(1);
		if (!s[fd])
			return (NULL);
		s[fd][0] = '\0';
	}
	temp = read_str(s[fd], fd);
	if (!temp)
		return (free(s[fd]), s[fd] = NULL, NULL);
	s[fd] = temp;
	line = get_n_line(s[fd]);
	if (!line)
		return (free(s[fd]), s[fd] = NULL, NULL);
	s[fd] = get_string(s[fd]);
	if (!s[fd])
		return (free(line), line = NULL, NULL);
	return (line);
}
