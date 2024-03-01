/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:04:03 by dmachace          #+#    #+#             */
/*   Updated: 2023/02/15 13:42:21 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*ptr;

	ptr = malloc(sizeof(*s) * ft_strlen(s) + 1);
	if (ptr == NULL)
		return (0);
	i = 0;
	while (*s != '\0')
	{
		ptr[i] = f(i, *s);
		s++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/*char	prntup(unsigned int n, char c)
{
	n = n + 1;
	c = toupper(c);
	printf("%c", (c));
	return (c);
}

int	main(void)
{
	char s[] = "Hello World";
	printf("\n%s", ft_strmapi(s, prntup));
	return (0);
}*/