/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 16:03:37 by afrasch           #+#    #+#             */
/*   Updated: 2022/03/12 19:11:13 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	move(int keycode, t_param *param)
{
	int	re;
	int	im;

	re = (param->img.r_max - param->img.r_min);
	im = (param->img.i_max - param->img.i_min);
	if (keycode == ARROW_RIGHT)
	{
		param->img.r_max -= re * 0.01;
		param->img.r_min -= re * 0.01;
	}
	if (keycode == ARROW_LEFT)
	{
		param->img.r_max += re * 0.01;
		param->img.r_min += re * 0.01;
	}
	if (keycode == ARROW_UP)
	{
		param->img.i_max -= im * 0.01;
		param->img.i_min -= im * 0.01;
	}
	if (keycode == ARROW_DOWN)
	{
		param->img.i_max += im * 0.01;
		param->img.i_min += im * 0.01;
	}
	put_image(param);
}

void	set_zoom(int	mousecode, int *x, int *y, t_param *param)
{
	double	zoom;

	if (mousecode == WHEEL_DOWN)
		zoom = 0.7;
	if (mousecode == WHEEL_UP)
		zoom = 1.3;
	pixel_to_scale(x, y, param);
	param->img.r_max = param->img.r_pos
		+ (param->img.r_max - param->img.r_pos) * zoom;
	param->img.r_min = param->img.r_pos
		+ (param->img.r_min - param->img.r_pos) * zoom;
	param->img.i_max = param->img.i_pos
		+ (param->img.i_max - param->img.i_pos) * zoom;
	param->img.i_min = param->img.i_pos
		+ (param->img.i_min - param->img.i_pos) * zoom;
	put_image(param);
}

void	pixel_to_scale(int *x, int *y, t_param *param)
{
	param->img.r_pos = param->img.r_min + (double) *x / (WIDTH - 1)
		* param->img.r_range;
	param->img.i_pos = param->img.i_max - (double) *y / (HEIGHT - 1)
		* param->img.i_range;
}
