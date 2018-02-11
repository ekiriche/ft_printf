/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trashcan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 19:15:26 by ekiriche          #+#    #+#             */
/*   Updated: 2018/02/11 16:22:13 by ekiriche         ###   ########.fr       */
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
					!pepePls(chunk->format[i + 1])))
			return (1);
		i++;
	}
	return (0);
}

void	case_point0(t_format *chunk, int *count)
{
	if (chunk->plus == 1 || chunk->space == 1)
		chunk->field_width--;
	while (chunk->field_width-- > chunk->precision)
	{
		*count += 1;
		ft_putchar(' ');
	}
	if (chunk->space == 1)
	{
		*count += 1;
		ft_putchar(' ');
	}
	if (chunk->conversion == 'o' && chunk->hash == 1)
	{
		*count += 1;
		ft_putchar('0');
	}

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

wchar_t	*ft_wstrdup(wchar_t *src)
{
	wchar_t	*cp;

	cp = (wchar_t*)malloc(sizeof(wchar_t) * ft_strlen((char*)src) + 1);
	if (cp == NULL)
		return (NULL);
	if (src == NULL)
		return (NULL);
	ft_strcpy((char*)cp, (char*)src);
	return (cp);
}
