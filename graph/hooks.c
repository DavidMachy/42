/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:01:41 by dmachace          #+#    #+#             */
/*   Updated: 2023/08/26 17:32:18 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_fractol *f, double zoom)
{
	
}

void	ft_hook(void *param)
{
	t_fractol	*f;
	int32_t		x;
	int32_t		y;
	static int	i;

	f = param;
	x = 0;
	y = 0;
	//printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
	if (mlx_is_key_down(f->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(f->mlx);
	mlx_get_mouse_pos(f->mlx, &x, &y);
	//printf("x:%d y:%d\n", x, y);
	if ((x < 0 || y < 0 || x > f->mlx.width || y > f->mlx.height) && i == 0)
	{
		printf("bye dude\n");
		i = 1;
	}
	if (x >= 0 && y >= 0 && x <= f->mlx.width && y <= f->mlx.height && i == 1)
	{
		printf("welcome back dude\n");
		i = 0;	
	}
}

void	close_act(void *param)
{
	//clean exit missing
	printf("I am closing\n");
}

/* void	scroll_act(double xdelta, double ydelta, void *param)
{
	if (ydelta > 0)
		//zoom in
	else if (ydelta < 0)
		//zoom out
} */

void	key_act(mlx_key_data_t key, void *param)
{
	static int	i;

	i = 0;
	if (key.key == MLX_KEY_1 && key.action == MLX_REPEAT)
	{
		printf("current num: %d\n", i);
		i++;
	}
	if (key.key == MLX_KEY_1 && key.action == MLX_RELEASE && i <= 100)
		i = 0;
	if (key.key == MLX_KEY_1 && key.action == MLX_REPEAT && i > 100)
	{
		printf("You held 1 you wally\n");
		i = 0;
	}
}

void	resize_act(int32_t width, int32_t height, void *param)
{
	/*f->mlx.width = width;
	f->mlx.height = height; */
	printf("Fok you resized me\n");
}
