/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/02/06 15:29:32 by dmachace          #+#    #+#             */
/*   Updated: 2023/02/06 15:29:32 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;

	ptr = malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2)
				+ 1));
	if (ptr == NULL)
		return (0);
	i = 0;
	while (*s1 != '\0')
	{
		ptr[i] = *s1;
		s1++;
		i++;
	}
	while (*s2 != '\0')
	{
		ptr[i] = *s2;
		s2++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/*int main(void)
{
    char s1[] = "Hello ";
    char s2[] = "World";

    printf("%s\n", ft_strjoin(s1, s2));
    return (0);
}*/