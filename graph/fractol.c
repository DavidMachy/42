/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 13:29:21 by dmachace          #+#    #+#             */
/*   Updated: 2023/08/14 15:45:52 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft/libft.h"

//gcc fractol.c libmlx42.a -Iinclude -ldl -lglfw -pthread -lm

int	arg_help(void)
{
	/* ft_ */printf("%s\n%s\n%s\n%s\n",
		"Invalid arguments, correct usage: ./fractol <type> <parameters>",
		"Types: J (=Julia set), M (=Mandelbrot set)",
		"Parameters: <colorshift> <numReal> <numImaginary>",
		"Note: num parameters can only be specified for Julia sets");
	exit(0);
}

int	check_args(int ac, char **av)
{
	if (ac > 1)	
	{
		if ((ac == 2 || ac == 3) && (av[1][0] == 'M'))
		{
			
			return (1);
		}
		else if ((ac > 1 && ac < 6) && av[1][0] == 'J')
		{

			return (1);
		}
	}
	return (arg_help());
}

int	mandelbrot(double cr, double ci)
{
	int		n;
	double	zr;
	double	zi;
	double	tmp;

	zr = 0;
	zi = 0;
	n = 0;
	while (n < 1000)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		tmp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
		n++;
	}
	return (n);
}


int putclr(int o)
{
	int r = 0x55 + o;
	int g = 0xaa + o;
	int b = 0x22 + o;
	int a = 0xff + o;

	int x = r << 24 | g << 16 | b << 8 | a;
	//printf("%d\n", x);
	return (r << 24 | g << 16 | b << 8 | a);
}

int main(int ac, char **av)
{
	mlx_t	*mlx;
	mlx_image_t	*img;
	int i = 0;
	double numr;
	double numi;

	if (check_args(ac, av))
	{
		mlx_set_setting(MLX_STRETCH_IMAGE, 1);
		mlx = mlx_init(WIDTH, HEIGHT, "lmao", true);
		img = mlx_new_image(mlx, WIDTH, HEIGHT);
		mlx_image_to_window(mlx, img, 0, 0);

 		for(int k = 0; k < WIDTH; k++)
			for(int l = 0; l < HEIGHT; l++)
			{
				numr = -2.0 + (double)k * 3 / WIDTH;
				numi = -1.5 + (double)l * ((-1.5 + 3 * HEIGHT / WIDTH) + 1.5)/ HEIGHT;
				mlx_put_pixel(img, k, l, putclr(mandelbrot(numr, numi)));						//0x22BBFFFF
			}
		mlx_put_string(mlx, "Fuck me sideways", 50, 50);
		mlx_loop_hook(mlx, &ft_hook, mlx);									//ESC
		mlx_key_hook(mlx, key_act, mlx);      								//move, zoom, set change
   	 	//mlx_mouse_hook(mlx, mouse_act, mlx);  							//zoom
		mlx_close_hook(mlx, close_act, mlx);		//testies
		mlx_resize_hook(mlx, resize_act, mlx);		//testies
		//mlx_cursor_hook(mlx, cursor_act, mlx);	//testies
		mlx_loop(mlx);
		mlx_terminate(mlx);
	}
	return (0);
}