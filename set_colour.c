/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colour.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 11:38:25 by afrasch           #+#    #+#             */
/*   Updated: 2021/10/27 11:18:42 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	colouring(t_image *img, t_num *num)
{
	if (num->iter <= num->iter_max - 1)
	{
		img->colour = num->iter * img->colourshift;
		my_pixel_put(img);
	}
	else
	{
		img->colour = 0x00222322;
		my_pixel_put(img);
	}
}
