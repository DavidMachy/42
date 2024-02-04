/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:06:17 by dmachace          #+#    #+#             */
/*   Updated: 2023/02/21 14:06:17 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (start >= ft_strlen(s))
	{
		ptr = malloc(1);
		if (ptr == NULL)
			return (0);
		ptr[0] = '\0';
		return (ptr);
	}
	ptr = malloc(sizeof(*s) * (len + 1));
	if (ptr == NULL)
		return (0);
	i = 0;
	while (i != len && s[start + i] != '\0')
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/*int main()
{
    char const s[] = "MONO I MANO";
    unsigned int start = 0;
    size_t len = 4;
    printf("%s\n", ft_substr(s, start, len));
    return (0);
}*/