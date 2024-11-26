#include "get_next_line.h"

int main()
{
    int     fd = open("file.txt", 0100);
    char    *str;

    str = get_next_line(fd);
    printf("%s",str);
}