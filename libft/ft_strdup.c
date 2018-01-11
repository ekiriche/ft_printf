/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:51:26 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/11/07 11:51:31 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*cp;

	cp = (char*)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (cp == NULL)
		return (NULL);
	if (src == NULL)
		return (NULL);
	ft_strcpy(cp, src);
	return (cp);
}
