/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 22:57:24 by marvin            #+#    #+#             */
/*   Updated: 2023/07/15 22:57:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* "Stack" in this exercise refers to a linked list.*/

#include "push_swap.h"

int	ft_issorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b, int lst_len)
{
	if(lst_len == 2 && !ft_issorted)
		sa(stack_a);
	if(lst_len > 2 && lst_len <= 5 && !ft_issorted)
		sort_small(stack_a, stack_b, lst_len);
	if(lst_len > 5 && !ft_issorted)
		sort(stack_a, stack_b, lst_len);
}

int main(int ac, char **av)
{
    t_stack *stack_a;
    t_stack *stack_b;
	int		lst_len;

    if (ac < 2)
        return (0);
    if (!check_args(av))
		args_error(NULL, NULL);
	stack_a = fill_stack(ac, av);
	stack_b = NULL;
	lst_len = stack_size(stack_a);
	assign_index(stack_a, lst_len);
	push_swap(&stack_a, &stack_b, lst_len);
	list_free(&stack_a);
	list_free(&stack_b);
    return (0);
}