src = get_next_line.c get_next_line_utils.c
objs = ${src:.c=.o}
NAME = libget.a
#CFLAGS = -fsanitize=address

all:${NAME}

${NAME}:${objs}
	ar rcs $@ $^

clean:
	rm -f *.o

fclean:clean
	rm -f ${NAME}