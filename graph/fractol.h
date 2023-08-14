/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:46:58 by dmachace          #+#    #+#             */
/*   Updated: 2023/07/12 16:14:05 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"

# define WIDTH 900
# define HEIGHT 900

void	cursor_act(double xpos, double ypos, void *param);
void	close_act(void *param);
void	resize_act(int32_t width, int32_t height, void *param);
void	key_act(mlx_key_data_t key, void *param);
void	ft_hook(void *param);
int		check_args(int ac, char **av);
int		arg_help(void);

#endif