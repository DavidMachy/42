/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:39:34 by dmachace          #+#    #+#             */
/*   Updated: 2023/02/07 15:26:20 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}

/*int	main(void)
{
	int	c = 65;
	int	d = 'A';
	int	f = '#';
	
	c = ft_tolower(c);
	d = ft_tolower(d);
	f = ft_tolower(f); 
	printf("%c\n", c);
	printf("%c\n", d);
	printf("%c\n", f);
}*/