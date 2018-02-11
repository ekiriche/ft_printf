/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_c_start.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 15:38:49 by ekiriche          #+#    #+#             */
/*   Updated: 2018/02/11 13:20:54 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	deal_with_c(t_format *chunk, va_list arg, int *count)
{
	if (ft_strcmp(chunk->length_flag, "none") == 0)
		deal_with_c1(chunk, arg, count);
	else if (ft_strcmp(chunk->length_flag, "l") == 0)
		deal_with_c2(chunk, arg, count);
}

void	deal_with_c2(t_format *chunk, va_list arg, int *count)
{
	wchar_t c;

	c = va_arg(arg, int);
	counting_char(chunk, count);
	if (c > 127 && c <= 2047)
		*count += 1;
	else if (c > 2047 && c <= 65535)
		*count += 2;
	else if (c > 65535)
		*count += 3;
	step1_wchar(chunk, c);
}

void	step1_wchar(t_format *chunk, wchar_t c)
{
	if (chunk->minus == 1 && chunk->field_width != 0)
	{
		wchar_minus(chunk, c);
		return ;
	}
	while (chunk->field_width > 1)
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
	ft_putwchar(c);
	while (chunk->field_width > 1)
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
	counting_char(chunk, count);
	step1_char(chunk, i);
}

void	counting_char(t_format *chunk, int *count)
{
	if (chunk->field_width > 1)
		*count += chunk->field_width;
	else
		*count += 1;
}

void	step1_char(t_format *chunk, char c)
{
	if (chunk->minus == 1 && chunk->field_width != 0)
	{
		char_minus(chunk, c);
		return ;
	}
	while (chunk->field_width > 1)
	{
		if (chunk->zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		chunk->field_width--;
	}
	ft_putchar(c);
}

void	char_minus(t_format *chunk, char c)
{
	ft_putchar(c);
	while (chunk->field_width > 1)
	{
		ft_putchar(' ');
		chunk->field_width--;
	}
}
