/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 17:03:34 by marvin            #+#    #+#             */
/*   Updated: 2024/02/05 16:37:47 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*fill_stack(int ac, char **av)
{
	t_stack	*stack_a;
	long	n;
	int		i;

	stack_a = NULL;
	n = 0;
	i = 1;
	while (i < ac)
	{
		n = ft_atol(av[i]);
		if (n < INT_MIN || n > INT_MAX)
			args_error(&stack_a, NULL);
		if (i == 1)
			stack_a = lst_new((int)n);
		else
			lstadd_bottom(&stack_a, lst_new((int)n));
		i++;
	}
	return (stack_a);
}

void	assign_index(t_stack *stack, int lst_len)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		num;

	while (--lst_len > 0)
	{
		ptr = stack;
		highest = NULL;
		num = INT_MIN;
		while (ptr)
		{
			if (ptr->num == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->num > num && ptr->index == 0)
			{
				highest = ptr;
				num = ptr->num;
				ptr = stack;
			}
			else
				ptr = ptr->next;
		}
		if (highest)
			highest->index = lst_len;
	}
}
