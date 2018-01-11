/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 09:39:41 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/11/10 10:37:05 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*new;

	if (!lst)
		return (NULL);
	if (!(new = (*f)(lst)))
		return (NULL);
	tmp = new;
	while (lst->next)
	{
		lst = lst->next;
		if (!(tmp->next = (*f)(lst)))
			return (NULL);
		tmp = tmp->next;
	}
	return (new);
}
