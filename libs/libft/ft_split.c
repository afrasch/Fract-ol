/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 09:54:55 by afrasch           #+#    #+#             */
/*   Updated: 2021/06/30 14:40:55 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(const char *s, char c)
{
	int	truefalse;
	int	words;
	int	i;

	truefalse = 0;
	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			truefalse = 0;
		else if (truefalse == 0)
		{
			words++;
			truefalse = 1;
		}
		i++;
	}
	return (words);
}

static char	**ft_null(char **arr, int j)
{
	arr[j] = 0;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		words;
	int		i;
	int		j;
	int		start;

	if (!s)
		return (0);
	words = ft_word_count(s, c);
	arr = malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (0);
	i = 0;
	j = -1;
	while (++j < words)
	{
		while (s[i] == c && s[i])
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		arr[j] = ft_substr(s, start, i - start);
		i++;
	}
	return (ft_null(arr, j));
}
