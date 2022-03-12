/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 11:43:21 by afrasch           #+#    #+#             */
/*   Updated: 2021/10/27 11:43:28 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	put_julia(t_param *param)
{
	if (fractol_strcmp(param->win.argv[1], "Julia") == 0)
		julia(param);
	else if (fractol_strcmp(param->win.argv[1], "Julia2") == 0)
		julia2(param);
	else if (fractol_strcmp(param->win.argv[1], "Julia3") == 0)
		julia3(param);
}

void	set_julia(t_param *param)
{
	int	error;

	if (param->win.argc == 2)
		put_julia(param);
	error = 1;
	if (param->win.argc > 3)
	{
		param->num.j_c_r = ft_atod(param->win.argv[2], &error);
		if (error == -1 || param->num.j_c_r > 2.0 || param->num.j_c_r < -2.0)
			return (input_guide());
		param->num.j_c_i = ft_atod(param->win.argv[3], &error);
		if (error == -1 || param->num.j_c_i > 2.0 || param->num.j_c_i < -2.0)
			return (input_guide());
		put_julia(param);
	}
	return ;
}

void	check_fractal(t_param *param)
{
	if (param->win.argc < 2)
		return (input_guide());
	else if (fractol_strcmp(param->win.argv[1], "Mandelbrot") == 0)
		mandelbrot(&param->num);
	else if (fractol_strcmp(param->win.argv[1], "Mandelbrot2") == 0)
		mandelbrot2(&param->num);
	else if (fractol_strcmp(param->win.argv[1], "Mandelbrot3") == 0)
		mandelbrot3(&param->num);
	else if (fractol_strcmp(param->win.argv[1], "Burning_Ship") == 0)
		burningship(&param->num);
	else if (fractol_strcmp(param->win.argv[1], "Pomegranate") == 0)
		pomegranate(&param->num);
	else if (fractol_strcmp(param->win.argv[1], "Pomegranate2") == 0)
		pomegranate2(&param->num);
	else if (fractol_strcmp(param->win.argv[1], "Pomegranate3") == 0)
		pomegranate3(&param->num);
	else if (fractol_strcmp(param->win.argv[1], "Julia") == 0)
		set_julia(param);
	else if (fractol_strcmp(param->win.argv[1], "Julia2") == 0)
		set_julia(param);
	else if (fractol_strcmp(param->win.argv[1], "Julia3") == 0)
		set_julia(param);
	else
		input_guide();
}

void	input_guide(void)
{
	write(2, "\033[1;34m\n", 9);
	write(2, " ---------------------------------------------------------\n", 59);
	write(2, " Your input should look like one of the following options:\n", 59);
	write(2, " ---------------------------------------------------------\n", 59);
	write(2, "\033[0;32m\n", 9);
	write(2, "1) <./fractol Mandelbrot/ Mandelbrot2/ Mandelbrot3>\n\n", 53);
	write(2, "2) <./fractol Julia/ Julia2/ Julia3>\n\n", 38);
	write(2, "3) <./fractol Burning_Ship>\n\n", 29);
	write(2, "4) <./fractol Pomegranate/ Pomegranate2/ Pomegranate3>\n\n", 56);
	write(2, "5) <./fractol Julia> plus two floating numbers between ", 55);
	write(2, "-2 and 2,\n", 10);
	write(2, "   spaces inbetween\n\n\033[1;34m", 29);
	write(2, " ---------------------------\n", 29);
	write(2, " Once you're in you can also\n", 29);
	write(2, " ---------------------------\n\n", 30);
	write(2, "\033[0;32m> change fractals by their first letter\n\n", 49);
	write(2, "> change the colour scheme by pressing C\n\n", 43);
	write(2, "> activate/ deactivate moving Julia mode by ", 45);
	write(2, "pressing space\n", 15);
	write(2, "\033[1;34m\n", 9);
	write(2, " ------------------\n", 20);
	write(2, " Have fun exploring\n", 20);
	write(2, " ------------------\n", 20);
	write(2, "\033[0m\n", 6);
	exit(EXIT_FAILURE);
}
