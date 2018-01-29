/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trashcan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 19:15:26 by ekiriche          #+#    #+#             */
/*   Updated: 2018/01/29 17:12:17 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nbrlenlong(long long int num)
{
	int len;

	len = 1;
	if (num < 0)
	{
		len++;
		num = -num;
	}
	while (num / 10 > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

void	ft_putnbrlong(long long int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 9)
		ft_putnbrlong(n / 10);
	ft_putchar(n % 10 + '0');
}
