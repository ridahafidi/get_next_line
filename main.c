#include "get_next_line.h"

int main()
{
    int     fd = open("file.txt", 0100);
    int     fd1 = open("file1.txt", 0100);
    char    *str;

   while (str)
   {
    str = get_next_line(fd);
    if(!str)
        break;
    printf("%s", str);
    str = get_next_line(fd1);
    printf("%s", str);
    free(str);
   }
    close(fd);
    close(fd1);
    return (0);
}