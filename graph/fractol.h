/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:46:58 by dmachace          #+#    #+#             */
/*   Updated: 2023/08/22 18:02:16 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"

# define WIDTH 900
# define HEIGHT 900

typedef struct s_fractol
{
	void	*mlx;
	void	*img;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	double	giv_r;
	double	giv_i;
}	t_fractol;

void    init_clean(t_fractol *f);
void	cursor_act(double xpos, double ypos, void *param);
void	close_act(void *param);
void	resize_act(int32_t width, int32_t height, void *param);
void	key_act(mlx_key_data_t key, void *param);
void	ft_hook(void *param);
int		check_args(int ac, char **av);
int		arg_help(void);

#endif