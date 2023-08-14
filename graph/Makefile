NAME = fractol
SRCS = fractol.c
OBJS = ${SRCS:.c=.o}
LIBS := $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
CFLAGS := -Wall -Wextra -Werror
CC := cc

all: $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
libft:
	make -C libft
clean:
	rm -f ${OBJS}
	make -C libft clean
fclean: clean
	rm -f ${NAME} libft/libft.a
re: fclean all

.PHONY : all bonus libft clean fclean re