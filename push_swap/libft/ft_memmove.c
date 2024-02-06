/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:08:42 by dmachace          #+#    #+#             */
/*   Updated: 2023/02/15 17:27:01 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*tdest;
	char	*tsrc;

	tdest = (char *)dest;
	tsrc = (char *)src;
	if (dest > src)
	{
		while (n-- > 0)
			tdest[n] = tsrc[n];
	}
	else
		ft_memcpy(tdest, tsrc, n);
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