/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 09:37:07 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/11/10 11:29:49 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordnum(const char *s, char c)
{
	int		i;
	int		wnum;

	i = 0;
	wnum = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			wnum++;
		while (s[i] != c && s[i])
			i++;
	}
	return (wnum);
}

static int	ft_symbnum(const char *s, char c)
{
	int		i;

	i = 0;
	while (*s != c && *s)
	{
		s++;
		i++;
	}
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**res;
	int		len;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_wordnum(s, c);
	if (!(res = (char**)malloc(sizeof(char*) * len + 1)))
		return (NULL);
	while (*s && i < len)
	{
		j = 0;
		while (*s == c && *s)
			s++;
		if (!(res[i] = (char*)malloc(sizeof(char) * ft_symbnum(s, c) + 1)))
			return (NULL);
		while (*s != c && *s)
			res[i][j++] = *s++;
		res[i][j] = '\0';
		i++;
	}
	res[i] = NULL;
	return (res);
}
