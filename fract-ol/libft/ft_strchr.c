/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:59:40 by dmachace          #+#    #+#             */
/*   Updated: 2023/02/21 18:29:36 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	if (c == '\0')
	{
		while (*s != '\0')
			s++;
		return ((char *)s);
	}
	while (*s != '\0')
	{
		if (*s == (char) c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

/*int main(void)
{
    const char s[] = "NEMO lol";
    int c = 'l';
    char    *ptr;

    ptr = ft_strchr(s, c);
    if (ptr != NULL)
        printf("%s\n", ptr);
    else 
        printf("its NULL mate\n");
}*/