/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:26:33 by dmachace          #+#    #+#             */
/*   Updated: 2023/03/16 11:08:52 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_putchar(int c, int *len);
void	ft_putstr(char *s, int *len);
void	ft_nbr(int n, int *len);
void	ft_nbr_unsig(unsigned int n, int *len);
void	ft_conv_hex(unsigned long long n, char form, int *len);
void	ft_void_point(unsigned long long n, int *len);
void	ft_form_check(va_list *args, char form, int *len);
int		ft_printf(const char *form, ...);

#endif