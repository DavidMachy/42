/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:46:47 by dmachace          #+#    #+#             */
/*   Updated: 2023/02/16 15:01:19 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srcsiz;

	srcsiz = ft_strlen(src);
	if (size == 0)
		return (srcsiz);
	i = 0;
	while (src[i] != '\0' && i != size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srcsiz);
}

/*int	main(void)
{
	const char	src[] = "Manana";
	char	dest[] = "Rim";
    size_t size = 7;

    printf("%l\n", ft_strlcpy(dest, src, size));
}*/