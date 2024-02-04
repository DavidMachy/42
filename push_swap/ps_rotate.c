/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psrotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:46:35 by marvin            #+#    #+#             */
/*   Updated: 2024/02/03 17:46:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rotate(t_stack **stack)
{
    t_stack *tmp;
    t_stack *bottom;

    tmp = *stack;
    *stack = (*stack)->next;
    bottom = lst_last(*stack);
    tmp->next = NULL;
    bottom->next = tmp;
}

void    ra(t_stack **stack_a)
{
    rotate(stack_a);
    ft_putstr_fd("ra", 1);
}

void    rb(t_stack **stack_b)
{
    rotate(stack_b);
    ft_putstr_fd("rb", 1);
}

void    rr(t_stack **stack_a, t_stack **stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
    ft_putstr_fd("rr", 1);
}