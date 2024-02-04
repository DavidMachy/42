/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:47:33 by marvin            #+#    #+#             */
/*   Updated: 2024/02/03 17:47:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rev_rotate(t_stack **stack)
{
    t_stack *tmp;
    t_stack *bottom;
    t_stack *before_bot;

    bottom = lst_last(*stack);
    before_bot = lst_before_last(*stack);
    tmp = *stack;
    *stack = bottom;
    (*stack)->next = tmp;
    before_bot->next = NULL;
}

void    rra(t_stack **stack_a)
{
    rev_rotate(stack_a);
    ft_putstr_fd("rra", 1);
}

void    rrb(t_stack **stack_b)
{
    rev_rotate(stack_b);
    ft_putstr_fd("rrb", 1);
}

void    rrr(t_stack **stack_a, t_stack **stack_b)
{
    rev_rotate(stack_a);
    rev_rotate(stack_b);
    ft_putstr_fd("rrr", 1);
}