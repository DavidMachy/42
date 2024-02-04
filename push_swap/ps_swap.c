/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psswap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:46:06 by marvin            #+#    #+#             */
/*   Updated: 2024/02/03 17:46:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap(t_stack *stack)
{
    int tmp;

    if (stack == NULL || stack->next == NULL)
        return ;
    tmp = stack->num;
    stack->num = stack->next->num;    
    stack->next->num = tmp;
    tmp = stack->index;
    stack->index = stack->next->index;
    stack->next->index = tmp;
}

void    sa(t_stack **stack_a)
{
    swap(*stack_a);
    ft_putstr_fd("sa", 1);
}

void    sb(t_stack **stack_b)
{
    swap(*stack_b);
    ft_putstr_fd("sb", 1);
}

void    ss(t_stack **stack_a, t_stack **stack_b)
{
    swap(*stack_a);
    swap(*stack_b);
    ft_putstr_fd("ss", 1);
}