/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 13:38:24 by dpolosuk          #+#    #+#             */
/*   Updated: 2017/11/11 11:26:42 by dpolosuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*res;
	int		s_len;
	int		s_plen;
	int		i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s) - 1;
	s_plen = 0;
	i = 0;
	while ((s[s_len] == ' ' || s[s_len] == '\n' || s[s_len] == '\t') && s_len)
		s_len--;
	while ((s[s_plen] == ' ' || s[s_plen] == '\n' || s[s_plen] == '\t')
			&& s[s_plen])
		s_plen++;
	if (s_len < s_plen)
		s_len = s_plen;
	if (!(res = (char*)malloc(sizeof(char) * (s_len - s_plen) + 2)))
		return (NULL);
	while (s_plen <= s_len)
		res[i++] = s[s_plen++];
	res[i] = '\0';
	return (res);
}
