/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_s_start.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 17:19:50 by ekiriche          #+#    #+#             */
/*   Updated: 2018/02/05 15:54:27 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	deal_with_s(t_format *chunk, va_list arg, int *count)
{
	if (ft_strcmp(chunk->length_flag, "none") == 0)
		deal_with_s1(chunk, arg, count);
	else if (ft_strcmp(chunk->length_flag, "l") == 0)
			deal_with_s2(chunk, arg, count);
}

void	deal_with_s1(t_format *chunk, va_list arg, int *count)
{
	char	*str;
	void	*lul;

	lul = va_arg(arg, char*);
	if (lul == NULL)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(lul);
	counting_string(chunk, str, count);
	step1_string(chunk, str);
}

void	deal_with_s2(t_format *chunk, va_list arg, int *count)
{
	wchar_t	*str;

	str = va_arg(arg, wchar_t*);
//	if (str == NULL)
//		str = ft_wstrdup((wchar_t*)"(null)");
//	else
//		str = ft_wstrdup(str);
	counting_string(chunk, (char*)str, count);
	step1_wstring(chunk, str);
}

void	step1_wstring(t_format *chunk, wchar_t *str)
{
	if (chunk->minus == 1)
	{
		wstring_minus(chunk, str);
		return ;
	}
	if ((unsigned long int)chunk->precision < ft_strlen((char*)str) &&
			chunk->precision != 0)
		ft_strnclr((char*)str, chunk->precision);
	while ((unsigned long int)chunk->field_width > ft_strlen((char*)str) &&
			!ft_find_point0(chunk))
	{
		if (chunk->zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		chunk->field_width--;
	}
	if (ft_find_point0(chunk))
		while (chunk->field_width > 0)
		{
			if (chunk->zero == 1)
				ft_putchar('0');
			else
				ft_putchar(' ');
			chunk->field_width--;
		}
	else
		ft_putwstring(str);
}

void	wstring_minus(t_format *chunk, wchar_t *str)
{
	if ((unsigned long int)chunk->precision < ft_strlen((char*)str) &&
			chunk->precision != 0)
		ft_strnclr((char*)str, chunk->precision);
	ft_putwstring(str);
	while ((unsigned long int)chunk->field_width > ft_strlen((char*)str))
	{
		ft_putchar(' ');
		chunk->field_width--;
	}
}

void	counting_string(t_format *chunk, char *str, int *count)
{
	if ((unsigned long int)chunk->precision < ft_strlen(str) &&
			chunk->precision != 0)
		ft_strnclr(str, chunk->precision);
	if ((unsigned long int)chunk->field_width > ft_strlen(str) ||
			ft_find_point0(chunk))
		*count += chunk->field_width;
	else
		*count += ft_strlen(str);
}

void	step1_string(t_format *chunk, char *str)
{
	if (chunk->minus == 1)
	{
		string_minus(chunk, str);
		return ;
	}
	if ((unsigned long int)chunk->precision < ft_strlen(str) &&
			chunk->precision != 0)
		ft_strnclr(str, chunk->precision);
	while ((unsigned long int)chunk->field_width > ft_strlen(str) &&
			!ft_find_point0(chunk))
	{
		if (chunk->zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		chunk->field_width--;
	}
	if (ft_find_point0(chunk))
		while (chunk->field_width > 0)
		{
			if (chunk->zero == 1)
				ft_putchar('0');
			else
				ft_putchar(' ');
			chunk->field_width--;
		}
	else
		ft_putstr(str);
}

void	string_minus(t_format *chunk, char *str)
{
	if ((unsigned long int)chunk->precision < ft_strlen(str) &&
			chunk->precision != 0)
		ft_strnclr(str, chunk->precision);
	ft_putstr(str);
	while ((unsigned long int)chunk->field_width > ft_strlen(str))
	{
		ft_putchar(' ');
		chunk->field_width--;
	}
}
