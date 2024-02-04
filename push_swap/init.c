/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 17:03:34 by marvin            #+#    #+#             */
/*   Updated: 2023/07/16 17:03:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack fill_stack(int ac, char **av)
{
    t_stack *stack_a;
    long    n;
    int     i;

    stack_a = NULL;
    n = 0;
    i = 1;
    while (i < ac)
    {
        n = ft_atol(av[i]);
        if (n < INT_MIN || n > INT_MAX)
            args_error(stack_a, NULL);
        if (i = 1)
            stack_a = lst_new((int)n);
        else
            lstadd_bottom(&stack_a, lst_new(int)n);
        i++;
    }
    return (stack_a);
}

/*  General idea: We index each num in our list so that we have 
    an easier to work with set of nums
    How does it work: We iterate through a tmp list and put the 
    highest value to a tmp pointer and assign index if no higher value
    is found, rinse and repeat*/

void    assign_index(t_stack *stack, int lst_len)   //mcombeau posílá lst_len + 1
{
    t_stack *ptr;
    t_stack *highest;
    int     num;

    while(lst_len > 0)
    {
        ptr = stack;
        highest = NULL;
        num = INT_MIN;
        while (ptr)
        {
            if (ptr->num == INT_MIN && ptr->index == 0)
                ptr->index = 1;                     //if the num is INT_MIN we set it to lowest index
            if (ptr->num > num && ptr->index == 0)
            {
                highest = ptr;                      //we found the highest
                num = ptr->num;                     //we replace the value to compare
                ptr = stack;                        //we re-set the loop to compare with the new value
            }
            else
                ptr = ptr->next;                    //we iterate through the pointer list if no higher is found
        }
        if (highest)
            highest->index = lst_len--;
    }
}