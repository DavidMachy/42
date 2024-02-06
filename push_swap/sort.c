/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:31:35 by marvin            #+#    #+#             */
/*   Updated: 2024/02/06 15:14:39 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest_pos(t_stack **stack)
{
	t_stack	*tmp;
	int		smallest_ind;

	tmp = *stack;
	smallest_ind = find_smallest_index(*stack);
	assign_pos(stack);
	while (tmp->index != smallest_ind)
		tmp = tmp->next;
	return (tmp->pos);
}

void	effi_push(t_stack **stack_a, t_stack **stack_b, int lst_len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < lst_len && j < lst_len / 2)
	{
		if ((*stack_a)->index <= lst_len / 2)
		{
			pb(stack_a, stack_b);
			j++;
		}
		else
			ra(stack_a);
		i++;
	}
	while (j < lst_len - 3)
	{
		pb(stack_a, stack_b);
		j++;
	}
}

void	rotate_list(t_stack **stack, int lst_len)
{
	int	smallest;

	smallest = find_smallest_pos(stack);
	if (smallest < lst_len / 2)
	{
		while (smallest > 0)
		{
			ra(stack);
			smallest--;
		}
	}
	else
	{
		while (smallest < lst_len)
		{
			rra(stack);
			smallest++;
		}
	}
}

void	sort(t_stack **stack_a, t_stack **stack_b, int lst_len)
{
	effi_push(stack_a, stack_b, lst_len);
	sort_three(stack_a);
	while (*stack_b)
	{
		get_target_pos(stack_a, stack_b);
		calc_cost(stack_a, stack_b);
		move_cheapest(stack_a, stack_b);
	}
	if (!ft_issorted(*stack_a))
		rotate_list(stack_a, lst_len);
}
