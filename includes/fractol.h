/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 23:11:27 by afrasch           #+#    #+#             */
/*   Updated: 2021/10/24 20:32:48 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/*includes*/
# include "mlx.h"
# include "libft.h"
# include <unistd.h>
# include <math.h>
# include <stdio.h>

/*defines*/
# define WIDTH 1000
# define HEIGHT 1000
# define WHEEL_DOWN 4
# define WHEEL_UP 5
# define ESC 53
# define ITER_INCREASE1 24
# define ITER_INCREASE2 69
# define ITER_DECREASE1 27
# define ITER_DECREASE2 78
# define ARROW_UP 126
# define ARROW_DOWN 125
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define SPACE 49
# define M 46
# define J 38
# define P 35
# define B 11
# define C 8

/*structs*/
typedef struct s_image
{
	void			*img;
	char			*addr;
	int				bpp;
	int				llen;
	int				ndn;
	double			r_max;
	double			r_min;
	double			i_max;
	double			i_min;
	double			r_range;
	double			i_range;
	double			r_pos;
	double			i_pos;
	int				x;
	int				y;
	double			x_perc;
	double			y_perc;
	unsigned int	colour;
	int				colourshift;
	int				*colour_scheme;
}				t_image;

typedef struct s_window
{
	void	*mlx;
	void	*win;
	int		argc;
	char	**argv;
}				t_window;

typedef struct s_num
{
	int		iter;
	int		iter_max;
	double	c_real;
	double	c_ima;
	double	z_real;
	double	z_ima;
	double	j_c_r;
	double	j_c_i;
	int		bool;
	int		julia_bool;
}				t_num;

typedef struct s_param
{
	t_image		img;
	t_window	win;
	t_num		num;
}				t_param;

/*prototypes*/
int		main(int argc, char **argv);
int		fractol(int argc, char *argv[]);

void	window_init(t_param *param);
void	num_init(t_param *param);
void	my_pixel_put(t_image *image);
void	complex_nb(t_param *param);
void	put_image(t_param *param);
void	check_fractal(t_param *param);
void	colouring(t_image *img, t_num *num);

void	mandelbrot(t_num *num);
void	mandelbrot2(t_num *num);
void	mandelbrot3(t_num *num);
void	julia(t_param *param);
void	julia2(t_param *param);
void	julia3(t_param *param);
void	pomegranate(t_num *num);
void	pomegranate2(t_num *num);
void	pomegranate3(t_num *num);
void	burningship(t_num *num);

void	put_julia(t_param *param);
void	set_julia(t_param *param);

void	hooks(t_param *param);
int		key_hook(int keycode, t_param *param);
int		mouse_hook(int mousecode, int x, int y, t_param *param);
int		change_julia_set(int x, int y, t_param *param);
void	set_key_hooks(int keycode, t_param *param);
void	set_iter_hooks(int keycode, t_param *param);
void	set_fractal_hooks(int keycode, t_param *param);
void	set_zoom(int	mousecode, int *x, int *y, t_param *param);
void	set_space(t_param *param);
void	pixel_to_scale(int *x, int *y, t_param *param);

void	move(int keycode, t_param *param);
void	switch_colour(t_param *param);
void	switch_mandelbrot(t_param *param);
void	switch_julia(t_param *param);
void	switch_pomegranate(t_param *param);

int		fractol_strcmp(const char *str1, const char *str2);
void	input_guide(void);
int		exit_free(t_param *param);

#endif
