/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:01:31 by afrasch           #+#    #+#             */
/*   Updated: 2021/10/25 13:34:09 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int	key_hook(int keycode, t_param *param)
{
	set_key_hooks(keycode, param);
	set_iter_hooks(keycode, param);
	set_fractal_hooks(keycode, param);
	put_image(param);
	return (0);
}

int	exit_free(t_param *param)
{
	mlx_destroy_image(param->win.mlx, param->img.img);
	mlx_destroy_window(param->win.mlx, param->win.win);
	exit(EXIT_SUCCESS);
	return (0);
}

int	mouse_hook(int	mousecode, int x, int y, t_param *param)
{
	if (mousecode == WHEEL_UP || mousecode == WHEEL_DOWN)
		set_zoom(mousecode, &x, &y, param);
	return (0);
}

int	change_julia_set(int x, int y, t_param *param)
{
	if (x >= 0 && x <= WIDTH && y >= 0 && y <= HEIGHT)
	{
		if (param->num.julia_bool == 1 && param->num.bool == 1)
		{
			pixel_to_scale(&x, &y, param);
			param->num.j_c_r = param->img.r_pos;
			param->num.j_c_i = param->img.i_pos;
			put_image(param);
		}
	}
	return (0);
}

void	hooks(t_param *param)
{
	mlx_hook(param->win.win, 4, 0, mouse_hook, param);
	mlx_hook(param->win.win, 2, 0, key_hook, param);
	mlx_hook(param->win.win, 6, 0, change_julia_set, param);
	mlx_hook(param->win.win, 17, 0, exit_free, param);
}
