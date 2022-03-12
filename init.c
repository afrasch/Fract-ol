/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 21:02:10 by afrasch           #+#    #+#             */
/*   Updated: 2021/10/24 20:00:14 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	window_init(t_param *param)
{
	param->win.mlx = mlx_init();
	param->win.win = mlx_new_window(param->win.mlx, WIDTH, HEIGHT, "fract-ol");
	param->img.img = mlx_new_image(param->win.mlx, WIDTH, HEIGHT);
	param->img.addr = mlx_get_data_addr(param->img.img, &param->img.bpp,
			&param->img.llen, &param->img.ndn);
	param->img.r_min = -2;
	param->img.r_max = 2;
	param->img.i_min = -2;
	param->img.i_max = 2;
	param->num.iter_max = 20;
	param->num.j_c_r = 0.0;
	param->num.j_c_i = -0.8;
	param->num.bool = 0;
	param->num.julia_bool = 0;
}

void	my_pixel_put(t_image *image)
{
	char	*dest;

	dest = image->addr + (image->y * image->llen + image->x * (image->bpp / 8));
	*(unsigned int *)dest = image->colour;
}

void	complex_nb(t_param *param)
{
	param->num.c_real = param->img.r_min + param->img.x * param->img.x_perc;
	param->num.c_ima = param->img.i_max - param->img.y * param->img.y_perc;
}

void	num_init(t_param *param)
{
	param->img.r_range = param->img.r_max - param->img.r_min;
	param->img.i_range = param->img.i_max - param->img.i_min;
	param->img.x_perc = param->img.r_range / WIDTH;
	param->img.y_perc = param->img.i_range / HEIGHT;
}
