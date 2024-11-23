#include "get_next_line.h"

    int main()
    {
        int fd = open("file.txt",0100);
        char *str;
        str = malloc(sizeof(char));
        if(!str)
            exit(1);
        str = get_next_line(fd);
        printf("line = %s", str);
        str = get_next_line(fd);
       printf("line = %s", str);
        close(fd);
        return 0;
    }