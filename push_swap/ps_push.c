/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pspush.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:45:56 by marvin            #+#    #+#             */
/*   Updated: 2024/02/03 17:45:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push(t_stack **from, t_stack **to)
{
    t_stack *tmp;

    if (!*from)
        return ;
    tmp = *to;
    *to = *from
    (*to)->next = tmp;
    *from = (*from)->next;
}

void    pa(t_stack **stack_a, t_stack **stack_b)    //push from b to top of a
{
    push(stack_b, stack_a);
    ft_putstr_fd("pa", 1);
}
void    pb(t_stack **stack_a, t_stack **stack_b)    //push from a to top of b
{
    push(stack_a, stack_b);
    ft_putstr_fd("pb", 1);
}