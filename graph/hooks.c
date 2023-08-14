/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:01:41 by dmachace          #+#    #+#             */
/*   Updated: 2023/08/14 14:27:38 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void cursor_act(double xpos, double ypos, void* param)
{
	printf("xpos = %f  ypos = %f\n", xpos, ypos);
}

void close_act(void* param)
{
	printf("I am closing\n");
}

void	resize_act(int32_t width, int32_t height, void* param)
{
/* 	mlx_t* mlx;
	
	mlx = (mlx_t *)param;
	mlx->width = width;
	mlx->height = height; */
	printf("Fok you resized me\n");
}

void	key_act(mlx_key_data_t key, void* param)
{
	mlx_t* mlx = param;
	static int i = 0;

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

void ft_hook(void* param)
{
	mlx_t* mlx = param;
	int32_t x = 0;
	int32_t y = 0;
	static int i;

	//printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	mlx_get_mouse_pos(mlx, &x, &y);
	//printf("x:%d y:%d\n", x, y);
	if ((x < 0 || y < 0 || x > mlx->width || y > mlx->height) && i == 0)
	{
		printf("bye dude\n");
		i = 1;
	}
	if (x >= 0 && y >= 0 && x <= mlx->width && y <= mlx->height && i == 1)
	{
		printf("welcome back dude\n");
		i = 0;
	}
}