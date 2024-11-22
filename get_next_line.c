#include "get_next_line.h"

char	*extractline(char *str)
{
	size_t	len;
	static size_t start;
	char 	*line;
	
	len = 0;
	while (str[len])
	{
		if (str[len] == '\n')
		{
			start++;
			break;
		}
		start++;
		len++;
	}
	line = ft_substr(str, start,len);
	printf("%s", line);
	exit(1);
	return (line);
}

char	*get_line(int fd, char *buffer, char *save_buff)
{
	ssize_t	readbytes;
	char	*line;
	char	*newlinepos;

	while((readbytes = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if(!save_buff)
			save_buff = ft_strdup(buffer);
		else
			save_buff = ft_strjoin(save_buff, buffer);
		if(ft_strchr(save_buff, '\n'))
		{
			line = extractline(save_buff);
			return (line);
		}
	}
	return(NULL);
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
	line = get_line(fd, buffer, save_buff);
	return (line);
}
