/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 09:41:54 by afrasch           #+#    #+#             */
/*   Updated: 2021/10/19 20:15:46 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
/* Checks for a digit (0 through 9).Returns 1 for success. */
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
