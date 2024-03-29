/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 20:57:38 by afrasch           #+#    #+#             */
/*   Updated: 2021/10/19 20:30:03 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
/* Adds the element ’new’ at the beginning of the list.
   lst is the address of a pointer to the first link of a list.
   new is the address of a pointer to the element to be added to the list. */
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
