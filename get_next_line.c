#include "get_next_line.h"

size_t	is_newline(char *buff)
{
	size_t	i;

	i = 0;
	while (*buff)
	{
		if (*buff == '\n')
			i++;
		buff++;
	}
	return (i);
}
int	afternewline(char *buff)
{
	int	i;
	int	j;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
		{
			i++;
			;
			if (buff[i])
				return (1);
		}
		i++;
	}
	return (0);
}
size_t	lencounter(char *buff)
{
	int	len;

	len = 0;
	while(buff[len])
	{
		if (buff[len] == '\n')
			return (len);
		len++;
	}
	return(0);
}
void	fill(char *s1, char *s2, size_t len)
{
	while(len)
	{
		*s1 = *s2;
		s1++;
		s2++;
		len--;
	}
}
char	*takecareofthis(char *buff)
{
	char			*newbuff;
	static size_t	save_len;
	static char		*save_buff;

	save_buff = NULL;
	if (save_buff)
		buff = ft_strjoin(save_buff, buff);
	save_len = lencounter(buff);
	if(save_len)
	{
		newbuff = malloc(sizeof(char) * (save_len + 1));
		if (!newbuff)
			return (NULL);
		newbuff[save_len] = '\0';
		fill(newbuff, buff, save_len);
		save_buff = ft_strdup(buff + save_len);
	}
	return (buff);
}
char	*get_next_line(int fd)
{
	char	*line;
	char	*buffer;
	char	*save_buff;
	ssize_t	readbytes;

	if (fd < 0 || read(fd, buffer, BUFFER_SIZE) <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	buffer[BUFFER_SIZE] = '\0';
	if (!buffer)
		return (NULL);
	while ((readbytes = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if (!is_newline(buffer) && readbytes != BUFFER_SIZE)
			buffer = ft_strjoin(save_buff, buffer);
		save_buff = ft_strdup(buffer);
		if (is_newline(buffer) == 1 && !afternewline(buffer))
			return (buffer);
		else
		{
			buffer = takecareofthis(buffer);
			return (buffer);
		}
	}
	return(NULL);
}
