/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 17:28:27 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/11/08 13:07:17 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strlen(little) == 0)
		return ((char*)big);
	while (big[i])
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
