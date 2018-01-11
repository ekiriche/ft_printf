/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 13:41:47 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/11/10 10:42:56 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strlen(little) == 0)
		return ((char*)big);
	while (big[i] && i <= len - ft_strlen(little) && len >= ft_strlen(little))
	{
		j = 0;
		while (big[i + j] == little[j])
		{
			if (j == ft_strlen(little) - 1)
				return ((char*)big + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
