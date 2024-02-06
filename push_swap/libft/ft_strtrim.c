/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:24:49 by dmachace          #+#    #+#             */
/*   Updated: 2023/02/21 14:24:49 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	ptr = NULL;
	if (s1 != NULL && set != NULL)
	{
		i = 0;
		while (s1[i] && ft_strchr(set, s1[i]))
			i++;
		j = ft_strlen(s1);
		while (s1[j - 1] && ft_strchr(set, s1[j - 1]) && j > i)
			j--;
		ptr = malloc(sizeof(*s1) * (j - i + 1));
		if (ptr == NULL)
			return (0);
		ft_strlcpy(ptr, &s1[i], j - i + 1);
	}
	return (ptr);
}

/*int main()
{
    char const  s1[] = "  \t \t \n   \n\n\n\t";
    char const  set[] = " \n\t";
    printf("%s\n", ft_strtrim(s1, set));
    return (0);
}*/