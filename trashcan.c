/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trashcan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 19:15:26 by ekiriche          #+#    #+#             */
/*   Updated: 2018/02/15 12:38:13 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nbrlenlong(long long int num)
{
	int				len;
	long long int	temp;

	temp = num;
	len = 1;
	if (temp < 0)
	{
		len++;
		temp = -temp;
	}
	while (temp / 10 > 0)
	{
		temp /= 10;
		len++;
	}
	return (len);
}

void	ft_putnbrlong(long long int n)
{
	if ((unsigned long long int)n == -9223372036854775808U)
	{
		ft_putstr("-9");
		n = 223372036854775808;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 9)
		ft_putnbrlong(n / 10);
	ft_putchar(n % 10 + '0');
}

int		ft_find_point0(t_format *chunk)
{
	int	i;

	i = 0;
	while (chunk->format[i + 1] != '\0')
	{
		if (chunk->format[i] == '.' && (chunk->format[i + 1] == '0' ||
					!pepe_pls(chunk->format[i + 1])))
			return (1);
		i++;
	}
	return (0);
}

void	ft_putwchar(wchar_t wc)
{
	if (wc <= 127)
		ft_putchar(wc);
	else if (wc <= 2047)
	{
		ft_putchar((wc >> 6) + 0xC0);
		ft_putchar((wc & 0x3F) + 0x80);
	}
	else if (wc <= 65535)
	{
		ft_putchar((wc >> 12) + 0xE0);
		ft_putchar(((wc >> 6) & 0x3F) + 0x80);
		ft_putchar((wc & 0x3F) + 0x80);
	}
	else if (wc <= 1114111)
	{
		ft_putchar((wc >> 18) + 0xF0);
		ft_putchar(((wc >> 12) & 0x3F) + 0x80);
		ft_putchar(((wc >> 6) & 0x3F) + 0x80);
		ft_putchar((wc & 0x3F) + 0x80);
	}
}

void	ft_putwstring(wchar_t *str)
{
	while (*str)
	{
		ft_putwchar(*str);
		str += 1;
	}
}
