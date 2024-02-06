/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:55:56 by marvin            #+#    #+#             */
/*   Updated: 2024/02/06 15:16:41 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_highest_index(t_stack *stack)
{
	int	index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

int	find_smallest_index(t_stack *stack)
{
	int	index;

	index = stack->index;
	while (stack)
	{
		if (stack->index < index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

void	smallest_to_top(t_stack **stack)
{
	t_stack	*first;
	int		smallest;

	first = *stack;
	smallest = find_smallest_index(*stack);
	if ((*stack)->index == smallest)
		return ;
	else if ((*stack)->next->index == smallest
		|| (*stack)->next->next->index == smallest)
	{
		while (first->index != smallest)
		{
			ra(stack);
			first = *stack;
		}
	}
	else
	{
		while (first->index != smallest)
		{
			rra(stack);
			first = *stack;
		}
	}
}

void	sort_three(t_stack **stack)
{
	int	highest;

	highest = find_highest_index(*stack);
	if ((*stack)->index == highest)
		ra(stack);
	else if ((*stack)->next->index == highest)
		rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		sa(stack);
}

void	sort_small(t_stack **stack_a, t_stack **stack_b, int lst_len)
{
	if (lst_len == 3)
		sort_three(stack_a);
	if (lst_len == 4)
	{
		smallest_to_top(stack_a);
		pb(stack_a, stack_b);
		sort_three(stack_a);
		pa(stack_a, stack_b);
	}
	if (lst_len == 5)
	{
		smallest_to_top(stack_a);
		pb(stack_a, stack_b);
		smallest_to_top(stack_a);
		pb(stack_a, stack_b);
		sort_three(stack_a);
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
}
