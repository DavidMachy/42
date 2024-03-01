/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmachace <dmachace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:46:58 by dmachace          #+#    #+#             */
/*   Updated: 2024/02/28 17:06:02 by dmachace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include <math.h>

# define WIDTH 900
# define HEIGHT 900

typedef struct s_fractol
{
	void	*mlx;
	void	*img;
	int		set;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	double	giv_r;
	double	giv_i;
}			t_fractol;

/* init */
void		init_clean(t_fractol *f);
void		init_real(t_fractol *f);

/* hooks */
void		move(t_fractol *f, char dir, double center_r, double center_i);
void		ft_hook(void *param);
void		close_act(void *param);
void		scroll_act(double xdelta, double ydelta, void *param);

/* render */
int			get_rgba(int r, int g, int b);
int			putclr(int clr);
void		render(t_fractol *f);

/* fractals*/
int			mandelbrot(double cr, double ci);
int			julia(t_fractol *f, double zr, double zi);
int			burning(double cr, double ci);

/* main */
int			arg_help(void);
void		clean_exit(t_fractol *f);

/* arg_parse */
int			neg_check(char *s, int *neg);
double		ft_atof(char *s);
void		get_julia_values(t_fractol *f, int ac, char **av);
int			check_args(t_fractol *f, int ac, char **av);

#endif