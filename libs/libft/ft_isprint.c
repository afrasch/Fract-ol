/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 09:58:20 by afrasch           #+#    #+#             */
/*   Updated: 2021/10/19 20:17:10 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
/* Checks for any printable character including space. Returns 1 for success. */
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
