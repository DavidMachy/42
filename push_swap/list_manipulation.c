/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:49:29 by marvin            #+#    #+#             */
/*   Updated: 2024/01/30 12:49:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack lst_last(t_stack *stack)
{
    while (stack && stack->next)
        stack = stack->next;
    return (stack);
}

t_stack lst_before_last(t_stack *stack)
{
    while (stack && stack->next && stack->next->next)
        stack = stack->next;
    return (stack);
}

t_stack *lst_new(int n)
{
    t_stack *new;

    new = malloc(sizeof(new));
    if (!new)
        return (0);
    new->num = n;
    new->index = 0;
    new->next = NULL;
    return (new);
}

void    lstadd_bottom(t_stack **stack, t_stack *new)
{
    t_stack *bottom;

    if (!new)
        return ;
    if (!stack)
        *stack = new;
    bottom = lst_last(*stack);
    bottom->next = new;
}

int stack_size(t_stack *stack)
{
    int size;

    size = 0;
    if (!stack)
        return (0);
    while (stack)
    {
        stack = stack->next;
        size++;
    }
    return (size);
}
