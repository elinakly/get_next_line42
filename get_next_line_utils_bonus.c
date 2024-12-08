/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eklymova <eklymova@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:11:24 by eklymova          #+#    #+#             */
/*   Updated: 2024/12/04 23:27:22 by eklymova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

ssize_t	ft_strlen(char *s)
{
	ssize_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s, char *buff)
{
	char	*arr;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	arr = (char *)malloc((ft_strlen(s) + ft_strlen(buff) + 1) * sizeof(char));
	if (!arr)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		arr[i] = s[i];
		i++;
	}
	j = 0;
	while (buff[j] != '\0')
		arr[i++] = buff[j++];
	arr[i] = '\0';
	return (free(s), arr);
}

char	*get_n_line(char *s)
{
	char	*arr;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	arr = (char *)malloc((i + 2) * sizeof(char));
	if (!arr)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
	{
		arr[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		arr[i] = s[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char	*get_string(char *s)
{
	int		i;
	int		j;
	char	*arr;

	i = 0;
	if (!s)
		return (NULL);
	while (s && (s[i] != '\0' && s[i] != '\n'))
		i++;
	if (!s)
		return (free(s), s = NULL, NULL);
	arr = (char *)malloc(((ft_strlen(s) - i) + 1) * sizeof(char));
	if (!arr)
		return (free(s), s = NULL, NULL);
	if (s[i] == '\n')
		i++;
	j = 0;
	while (s[i] != '\0')
		arr[j++] = s[i++];
	arr[j] = '\0';
	return (free(s), s = NULL, arr);
}
