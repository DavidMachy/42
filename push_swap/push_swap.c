/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 22:57:24 by marvin            #+#    #+#             */
/*   Updated: 2024/02/06 15:17:44 by dmachace         ###   ########.fr       */
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
	if (lst_len == 2 && !ft_issorted(*stack_a))
		sa(stack_a);
	else if (lst_len > 2 && lst_len <= 5 && !ft_issorted(*stack_a))
		sort_small(stack_a, stack_b, lst_len);
	else if (lst_len > 5 && !ft_issorted(*stack_a))
		sort(stack_a, stack_b, lst_len);
}

/* void	readstack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp1 = *stack_a;
	t_stack *tmp2 = *stack_b;

	while (tmp1)
	{
		printf("%d\n", tmp1->num);
		tmp1 = tmp1->next;
	}

	while (tmp2)
	{
		printf("%dbbb\n", tmp2->num);
		tmp2 = tmp2->next;
	}
} 
	readstack(&stack_a, &stack_b);
*/

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		lst_len;

	if (ac < 2)
		return (0);
	if (!check_args(av))
		args_error(NULL, NULL);
	stack_a = fill_stack(ac, av);
	stack_b = NULL;
	lst_len = stack_size(stack_a);
	assign_index(stack_a, lst_len + 1);
	push_swap(&stack_a, &stack_b, lst_len);
	list_free(&stack_a);
	list_free(&stack_b);
	return (0);
}
