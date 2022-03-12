/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 16:02:16 by afrasch           #+#    #+#             */
/*   Updated: 2021/10/24 19:35:14 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	set_space(t_param *param)
{
	if (param->num.bool == 0)
		param->num.bool = 1;
	else if (param->num.bool == 1)
		param->num.bool = 0;
}

void	set_fractal_hooks(int keycode, t_param *param)
{
	if (keycode == M)
		switch_mandelbrot(param);
	if (keycode == J)
		switch_julia(param);
	if (keycode == B)
		param->win.argv[1] = "Burning_Ship";
	if (keycode == P)
		switch_pomegranate(param);
}

void	set_iter_hooks(int keycode, t_param *param)
{
	if (keycode == ITER_INCREASE1 || keycode == ITER_INCREASE2)
	{
		if (param->num.iter_max < 100)
			param->num.iter_max = param->num.iter_max + 10;
		else if (param->num.iter_max >= 100)
			param->num.iter_max = param->num.iter_max + 50;
	}
	if (keycode == ITER_DECREASE1 || keycode == ITER_DECREASE2)
		param->num.iter_max = param->num.iter_max - 20;
}

void	set_key_hooks(int keycode, t_param *param)
{
	if (keycode == ESC)
		exit_free(param);
	if (keycode == C)
		switch_colour(param);
	if (keycode == SPACE)
		set_space(param);
	if (keycode == ARROW_RIGHT || keycode == ARROW_LEFT
		|| keycode == ARROW_UP || keycode == ARROW_DOWN)
		move(keycode, param);
}
