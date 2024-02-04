/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 22:38:38 by marvin            #+#    #+#             */
/*   Updated: 2023/07/15 22:38:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <limits.h>

typedef struct s_stack
{
	int				num;
	int				index;
	struct s_stack	*next;
}				t_stack;

/*Push_swap*/
void push_swap(t_stack **stack_a, t_stack **stack_b, int lst_len);
int ft_issorted(t_stack *stack);

/*Args check*/
int strcmp_plus(char *s1, char *s2);
int is_nbr(char *s);
int is_zero(char *s);
int has_dupli(char **av);
int check_args(char **av);

/*Init*/
t_stack fill_stack(int ac, char **av);
void assign_index(t_stack *stack, int lst_len);

/*List manipulation*/
t_stack lst_last(t_stack *stack);
t_stack lst_before_last(t_stack *stack);
t_stack *lst_new(int n);
void lstadd_bottom(t_stack **stack, t_stack *new);
int stack_size(t_stack *stack);

/*Sort small*/
int find_highest_index(t_stack *stack);
int find_smallest_index(t_stack *stack);
void smallest_to_top(t_stack **stack);
void sort_three(t_stack **stack_a);
void sort_small(t_stack **stack_a, t_stack **stack_b, int lst_len);

/*Sort*/
void effi_push(t_stack **stack_a, t_stack **stack_b, int lst_len);
void rotate_list(t_stack **stack_a, int lst_len);
void sort(t_stack **stack_a, t_stack **stack_b, int lst_len);

/*Utils*/
long ft_atol(const char *ptr);
void list_free(t_stack **stack);
void args_error(t_stack **stack_a, t_stack **stack_b);

/*Actions*/
void swap(t_stack *stack);
void sa(t_stack **stack_a);
void sb(t_stack **stack_b);
void ss(t_stack **stack_a, t_stack **stack_b);
void rotate(t_stack **stack);
void ra(t_stack **stack_a);
void rb(t_stack **stack_b);
void rr(t_stack **stack_a, t_stack **stack_b);
void rev_rotate(t_stack **stack);
void rra(t_stack **stack_a);
void rrb(t_stack **stack_b);
void rrr(t_stack **stack_a, t_stack **stack_b);
void push(t_stack **src, t_stack **dest);
void pa(t_stack **stack_a, t_stack **stack_b);
void pb(t_stack **stack_a, t_stack **stack_b);

#endif