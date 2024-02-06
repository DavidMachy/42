/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:01:23 by dmachace          #+#    #+#             */
/*   Updated: 2023/02/21 13:16:38 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	i;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	i = nmemb * size;
	p = (void *)malloc(i);
	if (p == NULL)
		return (0);
	if (i / nmemb != size)
		return (0);
	ft_bzero(p, i);
	return (p);
}

/*int main(void)
{
    int *a;
    int *b;

    size_t  nmemb = 3;
    a = ft_calloc(nmemb, sizeof(int));
    b = calloc(nmemb, sizeof(int));
    free (a);
    free (b);
    return (0); 
}*/