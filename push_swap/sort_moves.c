/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:49:53 by dmachace          #+#    #+#             */
/*   Updated: 2024/02/06 15:14:48 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cost_rotate_both(t_stack **stack_a, t_stack **stack_b, int *cost_a,
		int *cost_b)
{
	if (*cost_a < 0 && *cost_b < 0)
	{
		while (*cost_a < 0 && *cost_b < 0)
		{
			rrr(stack_a, stack_b);
			(*cost_a)++;
			(*cost_b)++;
		}
	}
	else if (*cost_a > 0 && *cost_b > 0)
	{
		while (*cost_a > 0 && *cost_b > 0)
		{
			rr(stack_a, stack_b);
			(*cost_a)--;
			(*cost_b)--;
		}
	}
}

void	cost_rotate_a(t_stack **stack, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			while (*cost > 0)
			{
				ra(stack);
				(*cost)--;
			}
		}
		else if (*cost < 0)
		{
			while (*cost < 0)
			{
				rra(stack);
				(*cost)++;
			}
		}
	}
}

void	cost_rotate_b(t_stack **stack, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			while (*cost > 0)
			{
				rb(stack);
				(*cost)--;
			}
		}
		else if (*cost < 0)
		{
			while (*cost < 0)
			{
				rrb(stack);
				(*cost)++;
			}
		}
	}
}

void	cost_move(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b)
{
	if ((cost_a < 0 && cost_b < 0) || (cost_a > 0 && cost_b > 0))
		cost_rotate_both(stack_a, stack_b, &cost_a, &cost_b);
	cost_rotate_a(stack_a, &cost_a);
	cost_rotate_b(stack_b, &cost_b);
	pa(stack_a, stack_b);
}
