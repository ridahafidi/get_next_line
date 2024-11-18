#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

ssize_t	newline_position(char *buffer, ssize_t position)
{
	ssize_t	save;

	save = -1;
	while (position)
	{
		if (buffer[position] == '\n')
			save = position;
		position--;
	}
	return (save);
}

char	*savebytes(char *buffer, int position)
{
    char *newbuff;
    int i;
    
    i = 0;
    newbuff = malloc(sizeof(char) * (position + 1));
    if(!newbuff)
        return (NULL);
    while(position)
    {
        newbuff[i] = buffer[i];
        buffer++;
        newbuff++;
        position--;
    }
    newbuff[position] = '\0';
    return (newbuff);
}
char    *seperate(char *buffer, ssize_t position)
{
    ssize_t newpos;
    char *newbuffer;

    newpos = newline_position(buffer, position);
    newbuffer = savebytes(buffer, newpos);
    return (newbuffer);
}
char	*get_next_line(int fd)
{
	ssize_t	readbytes;
	char	*buffer;
	char	*new_buff;
	ssize_t	position;

	if (fd < 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	readbytes = read(fd, buffer, BUFFER_SIZE);
	new_buff = seperate(buffer, readbytes);
	return (new_buff);
}
