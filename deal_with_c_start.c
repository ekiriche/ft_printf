/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_c_start.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 15:38:49 by ekiriche          #+#    #+#             */
/*   Updated: 2018/02/15 12:49:50 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	deal_with_c(t_format *chunk, va_list arg, int *count)
{
	if (ft_strcmp(chunk->length_flag, "none") == 0 || MB_CUR_MAX == 1)
		deal_with_c1(chunk, arg, count);
	else if (ft_strcmp(chunk->length_flag, "l") == 0)
		deal_with_c2(chunk, arg, count);
}

void	deal_with_c2(t_format *chunk, va_list arg, int *count)
{
	wchar_t	c;
	int		len;

	len = 0;
	c = va_arg(arg, int);
	count_uni(c, &len);
	if (chunk->field_width > len)
		*count += chunk->field_width;
	else
		*count += len;
	step1_wchar(chunk, c);
}

void	step1_wchar(t_format *chunk, wchar_t c)
{
	int len;

	len = 0;
	count_uni(c, &len);
	if (chunk->minus == 1 && chunk->field_width != 0)
	{
		wchar_minus(chunk, c);
		return ;
	}
	while (chunk->field_width > len)
	{
		if (chunk->zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		chunk->field_width--;
	}
	ft_putwchar(c);
}

void	wchar_minus(t_format *chunk, wchar_t c)
{
	int len;

	len = 0;
	count_uni(c, &len);
	ft_putwchar(c);
	while (chunk->field_width > len)
	{
		ft_putchar(' ');
		chunk->field_width--;
	}
}

void	deal_with_c1(t_format *chunk, va_list arg, int *count)
{
	char	i;

	if (chunk->conversion == '%')
		i = '%';
	else
		i = va_arg(arg, int);
	if (chunk->field_width > 1)
		*count += chunk->field_width;
	else
		*count += 1;
	step1_char(chunk, i);
}
