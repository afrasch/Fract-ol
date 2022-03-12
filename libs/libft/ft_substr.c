/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 14:09:27 by afrasch           #+#    #+#             */
/*   Updated: 2021/08/03 13:34:20 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Parameters:
   #1. The string from which to create the substring.
   #2. The start index of the substring in the string ’s’.
   #3. The maximum length of the substring. */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*substr;

	substr = (char *)malloc(sizeof(char) * len + 1);
	if (substr == 0 || s == 0)
		return (0);
	i = 0;
	j = 0;
	while (s[j])
	{
		if (j >= start && i < len)
		{
			substr[i] = s[j];
			i++;
		}
		j++;
	}
	substr[i] = '\0';
	return (substr);
}
