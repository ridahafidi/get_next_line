int	afternewline(char *buff)
{
	int	i;
	int	j;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			{
                i++;;
                if (buff[i])
                    return (1);
            }
		i++;
	}
	return (0);
}
#include <stdio.h>
int main()
{
    char buffer [20] = "abcdefsdsdsdsd\n";
    printf("%d", afternewline(buffer));
}