   #include <unistd.h>
   #include <stdio.h>
   #include <fcntl.h>
   #include <stddef.h>
    #include <stdlib.h>
    #include "get_next_line.h"

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

char	*savebytes(char *buffer, ssize_t position)
{
    char *newbuff;

    newbuff = malloc(sizeof(char) * (position + 1));
    if(!newbuff)
        return (NULL);
    newbuff[position + 1] = '\0';
    while(position >= 0)
    {
        newbuff[position] = buffer[position];
        position--;
    }
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

    int main()
    {
        int fd = open("file.txt",0100);
        char *str;
        str = malloc(sizeof(char));
        str = get_next_line(fd);
        printf("%s", str);
        close(fd);
        return 0;
    }