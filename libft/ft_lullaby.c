/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lullaby.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 16:11:33 by ekiriche          #+#    #+#             */
/*   Updated: 2017/11/04 16:20:41 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lullaby(unsigned int n)
{
	char			*ans;
	unsigned int	i;

	i = 0;
	if (!(ans = (char*)malloc(sizeof(*ans) * n + 1)))
		return (NULL);
	while (i < n)
	{
		ans[i] = 'z';
		i++;
	}
	ans[i] = '\0';
	return (ans);
}
