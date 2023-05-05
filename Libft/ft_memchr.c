/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:55:34 by dmachace          #+#    #+#             */
/*   Updated: 2023/02/21 13:34:30 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)ptr[i] == (unsigned char)c)
			return (ptr + i);
		i++;
	}
	return (0);
}

/*int main(void)
{
    const void *s;
    char ptr[] = "Hello World";
    int c = 'l';
    size_t n = 3;

    s = &ptr;
    if (ft_memchr(s, c, n) == NULL)
        printf("%d\n", 0);
    else
    {
        char    *p = (char *) ft_memchr(s, c, n);
        printf("%s\n", p);
    }
    return (0);
}*/