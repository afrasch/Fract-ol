/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 09:53:01 by afrasch           #+#    #+#             */
/*   Updated: 2021/10/19 20:14:46 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
/* Checks whether c is a char value that fits into the ASCII character set.
   Returns 1 for success. */
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
