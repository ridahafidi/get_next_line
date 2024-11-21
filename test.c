#include <stddef.h>

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
#include <stdio.h>
int main()
{
    char buffer [50] = "abcdefsdsdsdsd\n\n  asdasd  \ndasd\nasd\n";
    printf("%zu", is_newline(buffer));
}