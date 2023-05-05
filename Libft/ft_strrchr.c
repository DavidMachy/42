/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:59:42 by dmachace          #+#    #+#             */
/*   Updated: 2023/02/21 18:30:18 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	if (c == '\0')
	{
		while (*s != '\0')
			s++;
		return ((char *)s);
	}
	ptr = NULL;
	while (*s != '\0')
	{
		if (*s == (char) c)
			ptr = (char *)s;
		s++;
	}
	return (ptr);
}

/*int main(void)
{
    const char s[] = "NEMO lol";
    int c = 'l';
    char    *ptr;

    ptr = ft_strrchr(s, c);
    if (ptr != NULL)
        printf("%s\n", ptr);
    else 
        printf("its NULL mate\n");
}*/