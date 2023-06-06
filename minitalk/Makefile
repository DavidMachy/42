SRCS = server.c client.c
OBJS = ${SRCS:.c=.o}
CFLAGS := -Wall -Wextra -Werror
CC := cc

all: server client

server: server.o libft
	$(CC) -o $@ $< -Llibft -lft
client: client.o libft
	$(CC) -o $@ $< -Llibft -lft
.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
libft:
	make -C libft
clean:
	rm -f ${OBJS}
	make -C libft clean
fclean: clean
	rm -f server client libft/libft.a
re: fclean all

.PHONY : all bonus libft clean fclean re
