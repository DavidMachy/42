/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:39:34 by dmachace          #+#    #+#             */
/*   Updated: 2023/02/07 15:26:26 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c = c - 32;
	return (c);
}

/*int	main(void)
{
	int	c = 65;
	int	d = 'A';
	int	f = '#';
	
	c = ft_toupper(c);
	d = ft_toupper(d);
	f = ft_toupper(f); 
	printf("%c\n", c);
	printf("%c\n", d);
	printf("%c\n", f);
}*/