/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:30:49 by afrasch           #+#    #+#             */
/*   Updated: 2021/07/07 21:50:32 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	j;
	size_t	result;

	i = ft_strlen(dest);
	result = ft_strlen((char *)src);
	if (destsize <= i)
		result += destsize;
	else
		result += i;
	j = 0;
	while (src[j] && (i + 1) < destsize)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (destsize > 0 && i <= destsize)
		dest[i] = '\0';
	return (result);
}
