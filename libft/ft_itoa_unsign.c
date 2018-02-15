/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 14:36:15 by ekiriche          #+#    #+#             */
/*   Updated: 2018/02/15 12:10:28 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long long int	ft_numlen_unsign(unsigned long long int n)
{
	unsigned long long int i;

	i = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char							*ft_itoa_unsign(unsigned long long int n)
{
	char						*ans;
	unsigned long long int		i;
	unsigned long long int		lul;

	i = ft_numlen_unsign(n);
	lul = i;
	ans = (char*)malloc(sizeof(char) * (ft_numlen_unsign(n) + 1));
	while (i--)
	{
		ans[i] = (n % 10) + '0';
		n /= 10;
	}
	ans[lul] = '\0';
	return (ans);
}
