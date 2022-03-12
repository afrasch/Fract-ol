/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrasch <afrasch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 09:36:26 by afrasch           #+#    #+#             */
/*   Updated: 2021/10/19 20:44:42 by afrasch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
/* Takes as a parameter an element and frees the memory of the element’s
   content using the function ’del’ given as a parameter. */
{
	if (!lst)
		return ;
	del(lst->content);
	free(lst);
}
