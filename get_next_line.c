#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

size_t	is_newline(char *buff)
{
	size_t	i;

	i = 0;
	while(*buff)
	{
		if(*buff == '\n')
			i++;
		buff++;
	}
	return (i);
}

char	*get_next_line(int fd)
{
	char 	*line;
	char	*buffer;
	char	*save_buff;
	ssize_t	readbytes;

	if(fd < 0 || read(fd, buffer, BUFFER_SIZE) <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while ((readbytes = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if (!is_newline(buffer) && readbytes != BUFFER_SIZE)
			buffer = strjoin(save_buff, buffer);
		save_buff = strdup(buffer);
		if (is_newline == 1)
			return (buffer);
		

	}
}
