/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 16:13:39 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/11/02 11:19:58 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	size_t	j;
	char	*res;

	i = 0;
	j = ft_strlen(s);
	res = 0;
	if (s[j] == '\0' && c == '\0')
		return ((char*)(s + j));
	while (j--)
	{
		if (s[j] == c)
			return ((char*)(s + j));
	}
	if (s[j] == '\0')
		return (NULL);
	return (NULL);
}
