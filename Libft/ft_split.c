/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:03:47 by dmachace          #+#    #+#             */
/*   Updated: 2023/02/21 12:21:01 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static size_t	count(char const *s, char c)
{
	unsigned int	i;
	size_t			n;

	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			n++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (n);
}

static char	*strall(const char *src, size_t n)
{
	char			*ptr;
	unsigned int	i;

	ptr = malloc(sizeof(*src) * n + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0' && i < n)
	{
		ptr[i] = src[i];
		i++;
	}
	while (i < n)
		ptr[i++] = '\0';
	ptr[i] = '\0';
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		i;
	int		j;
	int		k;

	ptr = (char **)malloc(sizeof(char *) * (count(s, c) + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		k = i;
		while (s[k] != c && s[k] != '\0')
			k++;
		if (k > i)
		{
			ptr[j++] = strall(s + i, k - i);
		}
		i = k;
	}
	ptr[j] = NULL;
	return (ptr);
}

/*int	main(void)
{
	char const s[] = "Hello Brave New World";
	char c = ' ';
	int i = 0;
	char ptr[4][10] = ft_split(s, c);
	while (i != 4)
	{
		printf("%s\n", ptr[i]);
		i++;
	}
	return (0);
}*/