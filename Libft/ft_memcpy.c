/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:50:49 by dmachace          #+#    #+#             */
/*   Updated: 2023/02/15 17:25:46 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*tdest;
	char	*tsrc;

	tdest = (char *)dest;
	tsrc = (char *)src;
	i = 0;
	while (i < n)
	{
		tdest[i] = tsrc[i];
		i++;
	}
	return (dest);
}

/*int	main(void)
{
	size_t	n = 6;
	char	mls[] = "NOM NOM";
	char    src[] = "Rameno";

	char *rptr = (char *) ft_memcpy(ptr, src, n);
	printf("%s\n", rptr);
	return (0);
}*/