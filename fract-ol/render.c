/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:54:59 by dmachace          #+#    #+#             */
/*   Updated: 2024/02/28 17:23:38 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_rgba(int r, int g, int b)
{
	int	a;

	r += 0x00;
	g += 0x00;
	b += 0x00;
	a = 0xff;
	return (r << 24 | g << 16 | b << 8 | a);
}

int	putclr(int clr)
{
	if (clr * clr * clr > 500)
		return (get_rgba(clr * clr * clr % 255, clr * clr * clr % 128, clr * clr
				* clr % 64));
	else
		return (get_rgba(clr % 255, clr % 128, clr % 64));
}

void	render(t_fractol *f)
{
	int		i;
	int		j;
	double	calc_r;
	double	calc_i;

	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < HEIGHT)
		{
			calc_r = f->min_r + (f->max_r - f->min_r) * (double)i / WIDTH;
			calc_i = f->max_i - (f->max_i - f->min_i) * (double)j / HEIGHT;
			if (f->set == 'M')
				mlx_put_pixel(f->img, i, j, putclr(mandelbrot(calc_r, calc_i)));
			else if (f->set == 'B')
				mlx_put_pixel(f->img, i, j, putclr(burning(calc_r, calc_i)));
			else if (f->set == 'J')
				mlx_put_pixel(f->img, i, j, putclr(julia(f, calc_r, calc_i)));
		}
	}
}
