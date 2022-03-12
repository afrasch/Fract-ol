/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 21:28:39 by afrasch           #+#    #+#             */
/*   Updated: 2021/10/24 19:02:47 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	burningship(t_num *num)
{
	double	temp;

	num->z_real = 0;
	num->z_ima = 0;
	num->iter = 0;
	while (num->iter < num->iter_max
		&& pow(fabs(num->z_real), 2) + pow(fabs(num->z_ima), 2) <= 4)
	{
		temp = pow(fabs(num->z_real), 2)
			- pow(fabs(num->z_ima), 2) + num->c_real;
		num->z_ima = 2 * fabs(num->z_real) * fabs(num->z_ima) + num->c_ima;
		num->z_real = temp;
		num->iter++;
	}
}
