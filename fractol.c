/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:02:24 by afrasch           #+#    #+#             */
/*   Updated: 2021/10/27 11:21:27 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int	fractol(int argc, char *argv[])
{
	t_param	param;

	param.win.argc = argc;
	param.win.argv = argv;
	window_init(&param);
	put_image(&param);
	hooks(&param);
	mlx_loop(param.win.mlx);
	return (0);
}
