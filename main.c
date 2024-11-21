#include "get_next_line.h"

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