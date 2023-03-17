/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:38:07 by dmachace          #+#    #+#             */
/*   Updated: 2023/03/16 14:36:44 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(int c, int *len)
{
	write(1, &c, 1);
	*len += 1;
}

void	ft_putstr(char *s, int *len)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		*len += 6;
	}
	else
	{
		while (s[i] != '\0')
			i++;
		write(1, s, i);
		*len += i;
	}
}

void	ft_nbr(int n, int *len)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		*len += 11;
	}
	else if (n == 0)
		ft_putchar('0', len);
	else
	{
		if (n < 0)
		{
			ft_putchar('-', len);
			n = -n;
		}
		if (n < 10)
			ft_putchar(n + '0', len);
		else
		{
			ft_nbr(n / 10, len);
			ft_putchar(n % 10 + '0', len);
		}
	}
}

void	ft_nbr_unsig(unsigned int n, int *len)
{
	if (n < 10)
		ft_putchar(n + '0', len);
	else
	{
		ft_nbr_unsig(n / 10, len);
		ft_putchar(n % 10 + '0', len);
	}
}

void	ft_conv_hex(unsigned long long n, char form, int *len)
{
	if (n >= 16)
	{
		ft_conv_hex(n / 16, form, len);
		ft_conv_hex(n % 16, form, len);
	}
	else
	{
		if (n < 10)
			ft_putchar(n + '0', len);
		else
		{
			if (form == 'x')
				ft_putchar(n + 87, len);
			if (form == 'X')
				ft_putchar(n + 55, len);
		}
	}
}
