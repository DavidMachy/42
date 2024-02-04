/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:46:40 by dmachace          #+#    #+#             */
/*   Updated: 2023/02/16 15:10:13 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>	

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	l;

	l = ft_strlen(dst);
	if (size > 0 && size > l)
	{
		i = l;
		j = 0;
		while (src[j] != '\0' && i != size - 1)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
		return (l + ft_strlen(src));
	}
	return (size + ft_strlen(src));
}

/*int	main(void)
{
	char	dest[20] = "Hello ";
	char	src[] = "World";
    size_t  size = 6;

	ft_strlcat(dest, src, size);
	printf("%s\n", dest);
}*/