/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:05:33 by dmachace          #+#    #+#             */
/*   Updated: 2023/02/07 15:42:44 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (str);
}

/*int	main(void)
{
	size_t	n = 6;
	int	c = 4;
	void	*ptr;
	char	mls[] = "NOM NOM";
	
	ptr = &mls;
	ft_memset(ptr, c, n);
	return (0);
}*/