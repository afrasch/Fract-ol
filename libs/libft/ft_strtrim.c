/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:39:34 by afrasch           #+#    #+#             */
/*   Updated: 2021/06/28 15:19:02 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_set_for_char(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strimmed;
	size_t	i;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (0);
	start = 0;
	while (s1[start] && ft_check_set_for_char(s1[start], set))
		start++;
	end = ft_strlen((char *)s1);
	while (end > start && ft_check_set_for_char(s1[end - 1], set))
		end--;
	strimmed = (char *) malloc(end - start + 1);
	if (!strimmed)
		return (0);
	i = 0;
	while (start < end)
	{
		strimmed[i] = s1[start];
		i++;
		start++;
	}
	strimmed[i] = 0;
	return (strimmed);
}
