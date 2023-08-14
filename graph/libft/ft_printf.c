/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:28:19 by dmachace          #+#    #+#             */
/*   Updated: 2023/06/01 16:25:10 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_void_point(unsigned long long n, int *len)
{
	if (n != 0)
	{
		ft_printf_putchar('0', len);
		ft_printf_putchar('x', len);
		ft_conv_hex(n, 'x', len);
	}
	else
		ft_printf_putstr("(nil)", len);
}

void	ft_form_check(va_list *args, char form, int *len)
{
	if (form == 'c')
		ft_printf_putchar(va_arg(*args, int), len);
	else if (form == 's')
		ft_printf_putstr(va_arg(*args, char *), len);
	else if (form == 'p')
		ft_void_point(va_arg(*args, unsigned long long), len);
	else if (form == 'd' || form == 'i')
		ft_nbr(va_arg(*args, int), len);
	else if (form == 'u')
		ft_nbr_unsig(va_arg(*args, unsigned int), len);
	else if (form == 'x' || form == 'X')
		ft_conv_hex(va_arg(*args, unsigned int), form, len);
	else if (form == '%')
		ft_printf_putchar('%', len);
}

int	ft_printf(const char *form, ...)
{
	int		i;
	int		len;
	va_list	args;

	va_start(args, form);
	len = 0;
	i = 0;
	while (form[i] != '\0')
	{
		if (form[i] == '%')
		{
			ft_form_check(&args, form[i + 1], &len);
			i++;
		}
		else
			ft_printf_putchar((char)form[i], &len);
		i++;
	}
	va_end(args);
	return (len);
}

/*int	main(void)
{
	char *arr = " fghjghj se 235y: dr`";
	int n, res1, res2;
	char c = 'M';
	unsigned int p = 123;
	n = -2647678;
	res1 = ft_printf("%s\n", arr);
	res2 = printf("%s\n", arr);
	res1 = ft_printf("deci %d\t \n", n);
	res2 = printf("deci %d\t \n", n);
	res1 = ft_printf("chacha %c\n", c);
	res2 = printf("chacha %c\n", c);
	res1 = ft_printf("int %i\n", n);
	res2 = printf("int %i\n", n);
	res1 = ft_printf("unsigned %u\n", p);
	res2 = printf("unsigned %u\n", p);
	res1 = ft_printf("heX %X\n", p);
	res2 = printf("heX %X\n", p);
	res1 = ft_printf("hexa %x\n", p);
	res2 = printf("hexa %x\n", p);
	res1 = ft_printf("percent %%\n");
	res2 = printf("percent %%\n");
	res1 = ft_printf("void*: %p %p\n", "0", "ll");
	res2 = printf("void*: %p %p\n", "0", "ll");
	printf("%i - %i\n", res1, res2);
}*/