/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:28:09 by marvin            #+#    #+#             */
/*   Updated: 2024/02/06 15:14:36 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *ptr)
{
	int		i;
	int		s;
	long	x;

	i = 0;
	while (ptr[i] == 32 || (ptr[i] >= 9 && ptr[i] <= 13))
		i++;
	s = 1;
	if (ptr[i] == '-' || ptr[i] == '+')
	{
		if (ptr[i] == '-')
			s = s * -1;
		i++;
	}
	x = 0;
	while (ptr[i] >= 48 && ptr[i] <= 57)
	{
		x = x * 10 + (ptr[i] - 48);
		i++;
	}
	return (x * s);
}

void	list_free(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	free(*stack);
}

void	args_error(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		list_free(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		list_free(stack_b);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	ft_abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}
