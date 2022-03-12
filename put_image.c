/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 16:49:54 by afrasch           #+#    #+#             */
/*   Updated: 2021/10/24 20:12:53 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	put_image(t_param *param)
{
	num_init(param);
	param->img.y = 0;
	while (param->img.y < HEIGHT)
	{
		param->img.x = 0;
		while (param->img.x < WIDTH)
		{
			complex_nb(param);
			check_fractal(param);
			colouring(&param->img, &param->num);
			param->img.x++;
		}
		param->img.y++;
	}
	mlx_put_image_to_window(param->win.mlx, param->win.win,
		param->img.img, 0, 0);
}
