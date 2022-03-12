/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 20:26:44 by afrasch           #+#    #+#             */
/*   Updated: 2021/06/27 16:38:17 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	i = ft_strlen((char *)str);
	while (i >= 0)
	{
		if (((char *)str)[i] == (unsigned char)c)
			return ((char *)str + i);
		i--;
	}
	if (c == 0)
		return ((char *)str + i);
	return (0);
}
