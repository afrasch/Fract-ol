/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 21:18:50 by afrasch           #+#    #+#             */
/*   Updated: 2021/10/19 21:13:54 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
/* Counts the number of elements in a list.
   lst is the beginning of the list. */
{
	int		i;
	t_list	*conductor;

	i = 0;
	conductor = lst;
	while (conductor)
	{
		conductor = conductor->next;
		i++;
	}
	return (i);
}
