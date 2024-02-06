# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 12:03:28 by dmachace          #+#    #+#              #
#    Updated: 2024/02/05 12:18:52 by dmachace         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		= gcc
NAME 	= push_swap
CFLAGS 	= -Wall -Wextra -Werror
SRCS 	= push_swap.c check_args.c init.c list_manipulation.c sort.c \
		sort_small.c calc_sort.c sort_moves.c utils.c \
		ps_push.c ps_swap.c ps_rotate.c ps_rev_rotate.c
OBJS 	= ${SRCS:.c=.o}
LIBFT 	= ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft
	${CC} ${CFLAGS} -o $(NAME) $(OBJS) ${LIBFT}
.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I. -I./libft
clean:
	${MAKE} clean -C ./libft
	rm -f ${OBJS}
fclean: clean
	${MAKE} fclean -C ./libft
	rm -f ${NAME}
re: fclean all

.PHONY : all clean fclean re
