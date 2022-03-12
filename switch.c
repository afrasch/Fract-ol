/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 16:00:54 by afrasch           #+#    #+#             */
/*   Updated: 2021/10/27 11:55:21 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

/* Birthdays: 1 Lis, 2 Pa, 3 Florian, 4 Tim, 5 Jascha, 6 Hannes, 7 random,
   8 Basti, 9 Ersin, 10 Angel */
void	switch_colour(t_param *param)
{
	static int	i;
	int			colour[10];

	colour[0] = 191292;
	colour[1] = 5651;
	colour[2] = 1987;
	colour[3] = 8121999;
	colour[4] = 2092000;
	colour[5] = 21591;
	colour[6] = 292191;
	colour[7] = 342001;
	colour[8] = 2972001;
	colour[9] = 921981;
	param->img.colourshift = colour[i % 10];
	i++;
	put_image(param);
}

void	switch_mandelbrot(t_param *param)
{
	static int	i;
	char		*mandelbrot[3];

	mandelbrot[0] = "Mandelbrot";
	mandelbrot[1] = "Mandelbrot2";
	mandelbrot[2] = "Mandelbrot3";
	param->win.argv[1] = mandelbrot[i % 3];
	i++;
	put_image(param);
}

void	switch_julia(t_param *param)
{
	static int	i;
	char		*julia[3];

	julia[0] = "Julia";
	julia[1] = "Julia2";
	julia[2] = "Julia3";
	param->win.argv[1] = julia[i % 3];
	i++;
	param->num.julia_bool = 1;
	put_image(param);
}

void	switch_pomegranate(t_param *param)
{
	static int	i;
	char		*pomegranate[3];

	pomegranate[0] = "Pomegranate";
	pomegranate[1] = "Pomegranate2";
	pomegranate[2] = "Pomegranate3";
	param->win.argv[1] = pomegranate[i % 3];
	i++;
	put_image(param);
}
