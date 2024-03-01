# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 15:13:03 by dmachace          #+#    #+#              #
#    Updated: 2024/02/06 18:23:50 by dmachace         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror
NAME 		= fractol
SRCS 		= fractol.c hooks.c init.c arg_parse.c render.c fractals.c
OBJS 		= ${SRCS:.c=.o}
LIBFT		= ./libft/libft.a
MLX			= ./MLX42/libmlx42.a
MLX_FLAGS	= -ldl -lglfw -pthread -lm
LIBS 		= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm


all: $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I. -I./libft
$(NAME): $(OBJS)
	make -C ./libft
	${CC} ${CFLAGS} -o $(NAME) $(OBJS) $(MLX) $(MLX_FLAGS) ${LIBFT}
clean:
	${MAKE} clean -C libft
	rm -f ${OBJS}
fclean: clean
	${MAKE} fclean -C libft
	rm -f ${NAME}
re: fclean all

.PHONY : all clean fclean re