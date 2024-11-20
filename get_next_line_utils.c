#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*str;

	len = ft_strlen(s);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while(len)
    {
        *str = s;
        str++;
        s++;
        len--;
    }
    *str = '\0';
	return (str);
}
