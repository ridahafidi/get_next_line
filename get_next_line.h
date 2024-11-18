#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

typedef struct s_list
{
	char			*buffer;
	struct s_list	*next;
}					t_list;
char *get_next_line(int fd);
int newline(char c);
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif
#endif