/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:08:23 by dmachace          #+#    #+#             */
/*   Updated: 2023/02/07 15:23:06 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *ptr)
{
	int	i;
	int	s;
	int	x;

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

/*int main(void)
{
    const char ptr[] = "      -1464asd45";

    printf("%d\n", ft_atoi(ptr));
}*/