/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_s_start.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 17:19:50 by ekiriche          #+#    #+#             */
/*   Updated: 2018/02/08 15:59:44 by ekiriche         ###   ########.fr       */
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
	size_t	i;
	int		lul;
	int		prcs;

	i = 0;
	str = va_arg(arg, wchar_t*);
	if (str == NULL)
	{
		counting_string(chunk, "(null)", count);
		step1_string(chunk, "(null)");
		return ;
	}
	if (chunk->precision != 0 && chunk->precision < (int)ft_wstrlen(str) && !ft_find_point0(chunk))
	{
		prcs = chunk->precision;
		while (prcs > 0)
		{
			lul = 0;
			count_uni(str[i], &lul);
			prcs -= lul;
			if (prcs >= 0)
				count_uni(str[i], count);
			i++;
		}
		if (chunk->field_width > chunk->precision)
			*count += chunk->field_width - chunk->precision - 1 + i;
	}
	else while (str[i] != '\0' && !ft_find_point0(chunk))
	{
		if (str[i] > 127 && str[i] <= 2047)
			*count += 2;
		else if (str[i] > 2047 && str[i] <= 65535)
			*count += 3;
		else if (str[i] > 65535)
			*count += 4;
		else if (str[i] <= 127)
			*count += 1;
		i++;
	}
	if (chunk->field_width > (int)ft_wstrlen(str) && !ft_find_point0(chunk))
		*count += chunk->field_width - (int)ft_wstrlen(str);
	if (ft_find_point0(chunk))
		*count += chunk->field_width;
	step1_wstring(chunk, str);
}

void	count_uni(wchar_t c, int *count)
{
		if (c > 127 && c <= 2047)
			*count += 2;
		else if (c > 2047 && c <= 65535)
			*count += 3;
		else if (c > 65535)
			*count += 4;
		else if (c <= 127)
			*count += 1;
}

void	holy_crap(t_format *chunk)
{
	while (chunk->field_width > 0)
	{
		if (chunk->zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		chunk->field_width--;
	}
}

void	step1_wstring(t_format *chunk, wchar_t *str)
{
	int i;
	int lul;

	i = 0;
	lul = 0;
	if (ft_find_point0(chunk))
	{
		holy_crap(chunk);
		return ;
	}
	if (chunk->minus == 1)
	{
		wstring_minus(chunk, str);
		return ;
	}
	while ((unsigned long int)chunk->field_width > ft_wstrlen(str) &&
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
	{
		if (chunk->precision != 0 && (size_t)chunk->precision < ft_wstrlen(str))
		{
			while (chunk->field_width > chunk->precision - 1 &&
			!ft_find_point0(chunk))
			{
				if (chunk->zero == 1)
					ft_putchar('0');
				else
					ft_putchar(' ');
				chunk->field_width--;
			}
			while (chunk->precision > 0 && str[i])
			{
				lul = 0;
				count_uni(str[i], &lul);
				chunk->precision -= lul;
				if (chunk->precision >= 0)
					ft_putwchar(str[i]);
				i++;
			}
		}
		else
			ft_putwstring(str);
	}
}

void	wstring_minus(t_format *chunk, wchar_t *str)
{
	if (chunk->precision != 0 && chunk->precision < (int)ft_wstrlen(str) && (size_t)chunk->precision < ft_wstrlen(str))
		ft_putwchar(str[0]);
	else
		ft_putwstring(str);
	while ((unsigned long int)chunk->field_width > ft_wstrlen(str))
	{
		ft_putchar(' ');
		chunk->field_width--;
	}
}

size_t	ft_wstrlen(wchar_t *str)
{
	size_t	i;
	size_t	len;

	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] > 127 && str[i] <= 2047)
			len += 2;
		else if (str[i] > 2047 && str[i] <= 65535)
			len += 3;
		else if (str[i] > 65535)
			len += 4;
		else if (str[i] <= 127)
			len += 1;
		i++;
	}
	return (len);
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
