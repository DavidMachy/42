/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 18:48:37 by dmachace          #+#    #+#             */
/*   Updated: 2024/02/28 11:50:41 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	neg_check(char *s, int *neg)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '-' && s[i] != '+' && !ft_isdigit(s[i]))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			*neg *= -1;
		i++;
	}
	return (i);
}

double	ft_atof(char *s)
{
	int		i;
	int		neg;
	double	n;
	double	div;

	neg = 1;
	n = 0;
	div = 0.1;
	i = neg_check(s, &neg);
	while (s[i] && ft_isdigit(s[i]) && s[i] != '.')
	{
		n = (n * 10.0) + (s[i] - '0');
		i++;
	}
	if (s[i] == '.')
		i++;
	while (s[i] && ft_isdigit(s[i]))
	{
		n += (s[i] - '0') * div;
		div *= 0.1;
		i++;
	}
	if (s[i] && !ft_isdigit(s[i]))
		return (-8);
	return (n * neg);
}

void	get_julia_values(t_fractol *f, int ac, char **av)
{
	if (f->set == 'J' && ac == 2)
	{
		f->giv_r = -0.75;
		f->giv_i = -0.09;
		return ;
	}
	if (!ft_strchr(av[2], '.') || !ft_strchr(av[3], '.'))
		arg_help();
	f->giv_r = ft_atof(av[2]);
	f->giv_i = ft_atof(av[3]);
	if (f->giv_r < -2.0 || f->giv_r > 2.0)
		arg_help();
	if (f->giv_i < -2.0 || f->giv_i > 2.0)
		arg_help();
}

int	check_args(t_fractol *f, int ac, char **av)
{
	if (ac > 1 && ac < 5)
	{
		if (ac == 2 && av[1][0] == 'M')
		{
			f->set = 'M';
			return (1);
		}
		else if ((ac == 2 || ac == 4) && av[1][0] == 'J')
		{
			f->set = 'J';
			get_julia_values(f, ac, av);
			return (1);
		}
		else if (ac == 2 && av[1][0] == 'B')
		{
			f->set = 'B';
			return (1);
		}
	}
	return (arg_help());
}
