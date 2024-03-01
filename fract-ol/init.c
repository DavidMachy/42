/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:56:55 by dmachace          #+#    #+#             */
/*   Updated: 2024/02/28 17:06:29 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_clean(t_fractol *f)
{
	f->mlx = NULL;
	f->img = NULL;
	f->set = -1;
	f->min_r = 0;
	f->max_r = 0;
	f->min_i = 0;
	f->max_i = 0;
	f->giv_r = 0;
	f->giv_i = 0;
}

void	init_real(t_fractol *f)
{
	if (f->set == 'J')
	{
		f->min_r = -2.0;
		f->max_r = 2.0;
		f->min_i = -2.0;
		f->max_i = 2.0;
	}
	else if (f->set == 'M' || f->set == 'B')
	{
		f->min_r = -2.0;
		f->max_r = 1.0;
		f->max_i = -1.5;
		f->min_i = 1.5;
	}
	f->mlx = mlx_init(WIDTH, HEIGHT, "Fractolio", true);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
}
