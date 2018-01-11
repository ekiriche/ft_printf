/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 13:48:27 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/11/07 14:51:58 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && *((unsigned char*)s1 + i) == *((unsigned char*)s2 + i))
		i++;
	if (i == n)
		return (0);
	else
		return (*((unsigned char*)s1 + i) - *((unsigned char*)s2 + i));
}
