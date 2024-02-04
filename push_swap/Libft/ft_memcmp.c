/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:27:05 by dmachace          #+#    #+#             */
/*   Updated: 2023/02/09 15:31:34 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;

	if (n == 0)
		return (0);
	a = (void *)s1;
	b = (void *)s2;
	i = 0;
	while (i < n - 1)
	{
		if (a[i] != b[i])
			return (a[i] - b[i]);
		i++;
	}
	return (a[i] - b[i]);
}

/*int main(void)
{
    char    s1[] = "ABA";
    char    s2[] = "ABA";
    size_t  n = 4;
    
    printf("%d\n", ft_memcmp(s1, s2, n));
    return (0);
}*/