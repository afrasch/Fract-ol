/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 13:27:38 by afrasch           #+#    #+#             */
/*   Updated: 2021/10/19 20:04:19 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_intlen(long long num, int base)
/* Takes a number and its base. Counts digits and returns the result. */
{
	int	i;

	i = 1;
	while (num >= base || num <= -base)
	{
		i++;
		num /= base;
	}
	return (i);
}
