/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:36:16 by marvin            #+#    #+#             */
/*   Updated: 2024/02/06 14:56:40 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_pos(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

int	calc_target_pos(t_stack **stack_a, int b_index, int target_index,
		int target_pos)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index > b_index && tmp->index < target_index)
		{
			target_index = tmp->index;
			target_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (target_index != INT_MAX)
		return (target_pos);
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index < target_index)
		{
			target_index = tmp->index;
			target_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (target_pos);
}

void	get_target_pos(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		target_pos;

	tmp = *stack_b;
	target_pos = 0;
	assign_pos(stack_a);
	assign_pos(stack_b);
	while (tmp)
	{
		target_pos = calc_target_pos(stack_a, tmp->index, INT_MAX, target_pos);
		tmp->target_pos = target_pos;
		tmp = tmp->next;
	}
}

void	calc_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		len_a;
	int		len_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	len_a = stack_size(tmp_a);
	len_b = stack_size(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->pos;
		if (tmp_b->pos > len_b / 2)
			tmp_b->cost_b = -1 * (len_b - tmp_b->pos);
		tmp_b->cost_a = tmp_b->target_pos;
		if (tmp_b->target_pos > len_a / 2)
			tmp_b->cost_a = -1 * (len_a - tmp_b->target_pos);
		tmp_b = tmp_b->next;
	}
}

void	move_cheapest(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		cost_a;
	int		cost_b;
	int		cheapest;

	tmp = *stack_b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (ft_abs(tmp->cost_a) + ft_abs(tmp->cost_b) < cheapest)
		{
			cheapest = ft_abs(tmp->cost_a) + ft_abs(tmp->cost_b);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	cost_move(stack_a, stack_b, cost_a, cost_b);
}
