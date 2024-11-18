   #include <unistd.h>
   #include <stdio.h>
   #include <fcntl.h>
   #include <stddef.h>
    #include <stdlib.h>
    #include "get_next_line.h"

int	newline_position(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\n')
	{
		i++;
	}
	return (i);
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
char	*get_next_line(int fd)
{
	ssize_t	readbytes;
	char	*buffer;
	char	*new_buff;
	int		position;

	if (fd < 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	readbytes = read(fd, buffer, BUFFER_SIZE);
	position = newline_position(buffer);
	new_buff = savebytes(buffer, position);
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