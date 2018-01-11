/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:26:22 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/11/09 14:58:03 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*tmp;
	t_list	*tmp_n;

	tmp = *alst;
	while (tmp)
	{
		tmp_n = tmp->next;
		(*del)((tmp)->content, (tmp)->content_size);
		free(tmp);
		tmp = tmp_n;
	}
	*alst = NULL;
}
