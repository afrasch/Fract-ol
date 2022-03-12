/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pomegranate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 16:42:07 by afrasch           #+#    #+#             */
/*   Updated: 2021/10/24 20:12:26 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	pomegranate(t_num *num)
{
	double	temp;

	num->z_real = 0;
	num->z_ima = 0;
	num->iter = 0;
	while (num->iter < num->iter_max
		&& pow(num->z_real, 2) + pow(num->z_ima, 2) <= 4)
	{
		temp = pow(num->z_real, 2) - pow(num->z_ima, 2)
			+ num->z_real + num->c_real;
		num->z_ima = 2 * num->z_real * num->z_ima + num->z_ima + num->c_ima;
		num->z_real = temp;
		num->iter++;
	}
}

void	pomegranate2(t_num *num)
{
	double	temp;

	num->z_real = 0;
	num->z_ima = 0;
	num->iter = 0;
	while (num->iter < num->iter_max
		&& pow(num->z_real, 2) + pow(num->z_ima, 2) <= 4)
	{
		temp = -3 * num->z_real * pow(num->z_ima, 2) + pow(num->z_real, 3)
			+ num->z_real + num->c_real;
		num->z_ima = 3 * pow(num->z_real, 2) * num->z_ima - pow(num->z_ima, 3)
			+ num->z_ima + num->c_ima;
		num->z_real = temp;
		num->iter++;
	}
}

void	pomegranate3(t_num *num)
{
	double	temp;

	num->z_real = 0;
	num->z_ima = 0;
	num->iter = 0;
	while (num->iter < num->iter_max
		&& pow(num->z_real, 2) + pow(num->z_ima, 2) <= 4)
	{
		temp = -6 * pow(num->z_real, 2) * pow(num->z_ima, 2)
			+ pow(num->z_real, 4) + pow(num->z_ima, 4)
			+ num->z_real + num->c_real;
		num->z_ima = 4 * pow(num->z_real, 3) * num->z_ima - 4 * num->z_real
			* pow(num->z_ima, 3) + num->z_ima + num->c_ima;
		num->z_real = temp;
		num->iter++;
	}
}
