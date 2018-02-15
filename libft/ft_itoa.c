/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpolosuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 13:09:51 by dpolosuk          #+#    #+#             */
/*   Updated: 2018/02/15 12:09:36 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long int		ft_dgtsinnum(long long int n)
{
	int		i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

static char					*ft_less(long long int n, char *res)
{
	long long int		i;
	long long int		len;

	len = ft_dgtsinnum(n);
	n *= -1;
	i = len + 1;
	while (i--)
	{
		res[i] = (n % 10) + '0';
		n /= 10;
	}
	res[0] = '-';
	res[len + 1] = '\0';
	return (res);
}

static char					*ft_else(long long int n, char *res)
{
	long long int		i;
	long long int		len;

	len = ft_dgtsinnum(n);
	i = len;
	while (i--)
	{
		res[i] = (n % 10) + '0';
		n /= 10;
	}
	res[len] = '\0';
	return (res);
}

static char					*ft_kostyl(char *res)
{
	res[0] = '-';
	res[1] = '2';
	res[2] = '1';
	res[3] = '4';
	res[4] = '7';
	res[5] = '4';
	res[6] = '8';
	res[7] = '3';
	res[8] = '6';
	res[9] = '4';
	res[10] = '8';
	res[11] = '\0';
	return (res);
}

char						*ft_itoa(long long int n)
{
	long long int		len;
	char				*res;

	len = ft_dgtsinnum(n);
	if (n >= 0)
	{
		if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
	}
	else
	{
		if (!(res = (char*)malloc(sizeof(char) * (len + 2))))
			return (NULL);
	}
	if (n == -2147483648)
		res = ft_kostyl(res);
	else if (n < 0)
		res = ft_less(n, res);
	else
		res = ft_else(n, res);
	return (res);
}
