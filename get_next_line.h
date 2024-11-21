#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
typedef struct s_list
{
	char			*buffer;
	struct s_list	*next;
}					t_list;
char *get_next_line(int fd);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 12
#endif
#endif