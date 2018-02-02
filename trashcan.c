/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trashcan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 19:15:26 by ekiriche          #+#    #+#             */
/*   Updated: 2018/02/02 15:13:47 by ekiriche         ###   ########.fr       */
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
					chunk->format[i + 1] == chunk->conversion))
			return (1);
		i++;
	}
	return (0);
}

void	case_point0(t_format *chunk)
{
	if (chunk->plus == 1 || chunk->space == 1)
		chunk->field_width--;
	while (chunk->field_width-- > chunk->precision)
		ft_putchar(' ');
	if (chunk->space == 1)
		ft_putchar(' ');

}

unsigned long long int	ft_dectooctlong(unsigned long long int num)
{
	unsigned long long int	ans;
	unsigned long long int	temp;
	unsigned long long int	i;

	i = 1;
	ans = 0;
	while (num != 0)
	{
		temp = num % 8;
		num /= 8;
		ans += temp * i;
		i *= 10;
	}
	return (ans);
}
