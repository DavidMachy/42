SRC = ft_printf.c ft_functs.c
OBJ = ${SRC:.c=.o}
NAME = libftprintf.a
HEADER := ft_printf.h
CFLAGS := -Wall -Wextra -Werror
CC := gcc

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
clean: 
	rm -f ${OBJ}
fclean: clean
	rm -f ${NAME}
re: fclean all

.PHONY: all clean fclean re