/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:29:21 by dmachace          #+#    #+#             */
/*   Updated: 2024/02/28 09:53:50 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	arg_help(void)
{
	ft_printf("\n%s\n%s\n%s\n%s\n%s\n%s\n\n",
		"Invalid arguments, correct usage: ./fractol <type> <parameters>",
		"Types: J (=Julia set), M (=Mandelbrot set), B (=Burning Ship set)",
		"Parameters: <num_real> <num_imaginary> in this order",
		"num parameters can only be specified for Julia sets",
		"num parameters have to be written in double format",
		"num parameters have to range from -2.0 to 2.0");
	exit(0);
}

void	clean_exit(t_fractol *f)
{
	if (!f)
		return ;
	if (f->img)
		mlx_delete_image(f->mlx, f->img);
	if (f->mlx)
		mlx_close_window(f->mlx);
	return ;
}

int	main(int ac, char **av)
{
	t_fractol	*f;
	t_fractol	fract;

	if (ac < 2)
		arg_help();
	f = &fract;
	init_clean(f);
	check_args(f, ac, av);
	init_real(f);
	mlx_image_to_window(f->mlx, f->img, 0, 0);
	render(f);
	mlx_loop_hook(f->mlx, ft_hook, f);
	mlx_scroll_hook(f->mlx, scroll_act, f);
	mlx_close_hook(f->mlx, close_act, f);
	mlx_loop(f->mlx);
	mlx_terminate(f->mlx);
	return (0);
}
