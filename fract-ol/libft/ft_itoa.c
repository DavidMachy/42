/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:03:01 by dmachace          #+#    #+#             */
/*   Updated: 2023/02/08 15:33:22 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static char	*rev(char *num, char *ptr, int i)
{
	int	j;

	num[i] = '\0';
	i = 0;
	j = ft_strlen(num) - 1;
	while (j >= 0)
	{
		ptr[i] = num[j];
		i++;
		j--;
	}
	ptr[i] = '\0';
	return (ptr);
}

static char	*zerocheck(int n)
{
	char	*ptr;

	if (n == 0)
	{
		ptr = malloc(2);
		if (ptr == NULL)
			return (0);
		ptr[0] = '0';
		ptr[1] = '\0';
		return (ptr);
	}
	return (NULL);
}

static char	*mincheck(int n)
{
	char	*ptr;

	if (n == -2147483648)
	{
		ptr = malloc(12);
		if (ptr == NULL)
			return (0);
		ptr[0] = '-';
		ptr[1] = '2';
		ptr[2] = '1';
		ptr[3] = '4';
		ptr[4] = '7';
		ptr[5] = '4';
		ptr[6] = '8';
		ptr[7] = '3';
		ptr[8] = '6';
		ptr[9] = '4';
		ptr[10] = '8';
		ptr[11] = '\0';
		return (ptr);
	}
	return (NULL);
}

int	negcheck(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	char	num[12];
	int		i;
	int		s;

	if (zerocheck(n) != NULL)
		return (zerocheck(n));
	if (mincheck(n) != NULL)
		return (mincheck(n));
	s = negcheck(n);
	if (s == 1)
		n = -n;
	i = 0;
	while (n != 0)
	{
		num[i++] = n % 10 + '0';
		n = n / 10;
	}
	if (s == 1)
		num[i++] = '-';
	ptr = malloc(sizeof(*num) * i + 1);
	if (ptr == NULL)
		return (0);
	rev(num, ptr, i);
	return (ptr);
}

/*int	main(void)
{
	int n = -123456;
	printf("%s\n", ft_itoa(n));
	return (0);
}*/