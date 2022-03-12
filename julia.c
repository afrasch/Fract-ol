/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 16:43:01 by afrasch           #+#    #+#             */
/*   Updated: 2021/10/24 20:05:59 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	julia(t_param *param)
{
	double	temp;

	param->num.z_real = param->num.c_real;
	param->num.z_ima = param->num.c_ima;
	param->num.iter = 0;
	while (param->num.iter < param->num.iter_max
		&& pow(param->num.z_real, 2) + pow(param->num.z_ima, 2) <= 4)
	{
		temp = pow(param->num.z_real, 2) - pow(param->num.z_ima, 2)
			+ param->num.j_c_r;
		param->num.z_ima = 2 * param->num.z_real * param->num.z_ima
			+ param->num.j_c_i;
		param->num.z_real = temp;
		param->num.iter++;
	}
}

void	julia2(t_param *param)
{
	double	temp;

	param->num.z_real = param->num.c_real;
	param->num.z_ima = param->num.c_ima;
	param->num.iter = 0;
	while (param->num.iter < param->num.iter_max
		&& pow(param->num.z_real, 2) + pow(param->num.z_ima, 2) <= 4)
	{
		temp = -3 * param->num.z_real * pow(param->num.z_ima, 2)
			+ pow(param->num.z_real, 3) + param->num.j_c_r;
		param->num.z_ima = 3 * pow(param->num.z_real, 2) * param->num.z_ima
			- pow(param->num.z_ima, 3) + param->num.j_c_i;
		param->num.z_real = temp;
		param->num.iter++;
	}
}

void	julia3(t_param *param)
{
	double	temp;

	param->num.z_real = param->num.c_real;
	param->num.z_ima = param->num.c_ima;
	param->num.iter = 0;
	while (param->num.iter < param->num.iter_max
		&& pow(param->num.z_real, 2) + pow(param->num.z_ima, 2) <= 4)
	{
		temp = -6 * pow(param->num.z_real, 2) * pow(param->num.z_ima, 2)
			+ pow(param->num.z_real, 4)
			+ pow(param->num.z_ima, 4) + param->num.j_c_r;
		param->num.z_ima = 4 * pow(param->num.z_real, 3)
			* param->num.z_ima - 4 * param->num.z_real
			* pow(param->num.z_ima, 3) + param->num.j_c_i;
		param->num.z_real = temp;
		param->num.iter++;
	}
}
