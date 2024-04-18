CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror -pthread -g
NAME 		= philo
SRCS 		= philo.c init.c actions.c utils.c
OBJS 		= ${SRCS:.c=.o}

all: $(NAME)

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
$(NAME): $(OBJS)
	${CC} ${CFLAGS} -o $(NAME) $(OBJS)
clean:
	rm -f ${OBJS}
fclean: clean
	rm -f ${NAME}
re: fclean all

.PHONY : all clean fclean re
