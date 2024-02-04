/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:31:35 by marvin            #+#    #+#             */
/*   Updated: 2024/02/04 16:31:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    effi_push(t_stack **stack_a, t_stack **stack_b, int lst_len)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < lst_len && j < lst_len / 2)
    {
        if((*stack)->index <= lst_len / 2)
        {
            pb(stack_a, stack_b);
            j++;
        }
        else
            ra(stack_a);
        i++;
    }
    while (j != lst_len)
    {
        pb(stack_a, stack_b);
        j++;
    }
}

void    rotate_list(t_stack **stack, int lst_len)
{
    int smallest;

    smallest = find_smallest_index(*stack);
    while ((*stack)->index != smallest)
        rotate(stack);
}

void    sort(t_stack **stack_a, t_stack **stack_b, int lst_len)
{
    effi_push(stack_a, stack_b, lst_len);
    while (*stack_b)
    {

    }
    if (!ft_issorted(*stack_a))
        rotate_list(stack_a, lst_len);
}