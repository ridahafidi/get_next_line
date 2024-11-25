/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:03:40 by rhafidi           #+#    #+#             */
/*   Updated: 2024/11/25 21:39:58 by rhafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extractline(char *str, size_t *start)
{
	char	*line;
	int		newline;
	size_t	len;

	newline = 0;
	len = 0;
	if (!str || !start)
		return (NULL);
	while (str[*start + len] && str[*start + len] != '\n')
		len++;
	if (str[*start + len] == '\n')
	{
		line = ft_substr(str, *start, len + 1);
		newline = 1;
	}
	else
		line = ft_substr(str, *start, len);
	*start += len + newline;
	return (line);
}
static char	*get_rest_of_savebuff(char **save_buff, size_t *start)
{
	char	*line;

	line = extractline(*save_buff, start);
	if (*line == '\0')
	{
		free(*save_buff);
		*save_buff = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

static char	*get_line(int fd, char *buffer, char **save_buff)
{
	ssize_t			readbytes;
	char			*line;
	static size_t	start;

	line = NULL;
	while ((readbytes = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[readbytes] = '\0';
		if (!*save_buff)
			*save_buff = ft_strdup(buffer);
		else
			*save_buff = ft_strjoin(*save_buff, buffer);
		if (ft_strchr(*save_buff + start, '\n'))
		{
			line = extractline(*save_buff, &start);
			free(buffer);
			return (line);
		}
	}
	if (readbytes == 0 && !save_buff)
		return (NULL);
	if (*save_buff && (*save_buff + start) != '\0')
		line = get_rest_of_savebuff(save_buff, &start);
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*save_buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = get_line(fd, buffer, &save_buff);
	if (!line && save_buff)
	{
		free(save_buff);
		save_buff = NULL;
	}
	return (line);
}
