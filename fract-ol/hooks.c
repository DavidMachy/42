/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:01:41 by dmachace          #+#    #+#             */
/*   Updated: 2024/02/28 17:05:29 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move(t_fractol *f, char dir, double dif_r, double dif_i)
{
	dif_r = f->max_r - f->min_r;
	dif_i = f->max_i - f->min_i;
	if (dir == 'R')
	{
		f->min_r += dif_r * 0.2;
		f->max_r += dif_r * 0.2;
	}
	if (dir == 'L')
	{
		f->min_r -= dif_r * 0.2;
		f->max_r -= dif_r * 0.2;
	}
	if (dir == 'U')
	{
		f->min_i += dif_i * 0.2;
		f->max_i += dif_i * 0.2;
	}
	if (dir == 'D')
	{
		f->min_i -= dif_i * 0.2;
		f->max_i -= dif_i * 0.2;
	}
	render(f);
}

void	ft_hook(void *param)
{
	t_fractol	*f;

	f = param;
	if (mlx_is_key_down(f->mlx, MLX_KEY_ESCAPE))
		clean_exit(f);
	if (mlx_is_key_down(f->mlx, MLX_KEY_RIGHT))
		move(f, 'R', 0, 0);
	if (mlx_is_key_down(f->mlx, MLX_KEY_LEFT))
		move(f, 'L', 0, 0);
	if (mlx_is_key_down(f->mlx, MLX_KEY_UP))
		move(f, 'U', 0, 0);
	if (mlx_is_key_down(f->mlx, MLX_KEY_DOWN))
		move(f, 'D', 0, 0);
}

void	close_act(void *param)
{
	t_fractol	*f;

	f = param;
	clean_exit(f);
}

void	scroll_act(double xdelta, double ydelta, void *param)
{
	t_fractol	*f;
	double		dif_r;
	double		dif_i;
	double		zoom;

	(void)xdelta;
	f = param;
	if (ydelta > 0)
		zoom = 0.5;
	else if (ydelta < 0)
		zoom = 2;
	dif_r = f->max_r - f->min_r;
	dif_i = f->max_i - f->min_i;
	f->min_r = f->min_r + (dif_r - zoom * dif_r) / 2;
	f->max_r = f->min_r + zoom * dif_r;
	f->min_i = f->min_i + (dif_i - zoom * dif_i) / 2;
	f->max_i = f->min_i + zoom * dif_i;
	render(f);
}
