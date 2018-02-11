/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_s_start.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 17:19:50 by ekiriche          #+#    #+#             */
/*   Updated: 2018/02/11 18:56:34 by ekiriche         ###   ########.fr       */
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
	step1_string(chunk, str, count);
	ft_memdel((void**)&str);
//	ft_memdel((void**)&lul);
}

void	deal_with_s2(t_format *chunk, va_list arg, int *count)
{
	wchar_t	*str;

	str = va_arg(arg, wchar_t*);
	if (str == NULL)
	{
		step1_string(chunk, "(null)", count);
		return ;
	}
	step1_wstring(chunk, str, count);
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

void	holy_crap(t_format *chunk, int *count)
{
	while (chunk->field_width > 0)
	{
		if (chunk->zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		chunk->field_width--;
		*count += 1;
	}
}

void	step1_wstring(t_format *chunk, wchar_t *str, int *count)
{
	int	i;
	int	wut;
	int	wut2;

	if (ft_find_point0(chunk))
	{
		holy_crap(chunk, count);
		return ;
	}
	if (chunk->minus == 1)
	{
		wstring_minus(chunk, str, count);
		return ;
	}
	wut = 0;
	i = 0;
	if (chunk->precision != 0)
	{	
		while (chunk->precision > 0 && str[i])
		{
			wut2 = 0;
			count_uni(str[i], &wut);
			count_uni(str[i], &wut2);
			if (chunk->precision - wut < 0)
			{
				wut -= wut2;
				break ;
			}
			i++;
		}
		chunk->field_width -= wut;
	}
	if (wut == 0)
		chunk->field_width -= ft_wstrlen(str);
	while (chunk->field_width > 0)
	{
		*count += 1;
		if (chunk->zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		chunk->field_width--;
	}
	i = 0;
	wut2 = 0;
	if (wut == 0)
	{
		ft_putwstring(str);
		while (str[i])
		{
			count_uni(str[i], count);
			i++;
		}
	}
	while (wut > 0)
	{
		count_uni(str[i], &wut2);
		wut -= wut2;
		if (wut < 0)
			break;
		ft_putwchar(str[i]);
		i++;
		count_uni(str[i], count);
		wut2 = 0;
	}
}

void	wstring_minus(t_format *chunk, wchar_t *str, int *count)
{
	int	i;
	int	wut;
	int	wut2;

	wut = 0;
	i = 0;
	if (chunk->precision != 0)
	{	
		while (chunk->precision > 0 && str[i])
		{
			wut2 = 0;
			count_uni(str[i], &wut);
			count_uni(str[i], &wut2);
			if (chunk->precision - wut < 0)
			{
				wut -= wut2;
				break ;
			}
			i++;
		}
		chunk->field_width -= wut;
	}
	if (wut == 0)
		chunk->field_width -= ft_wstrlen(str);
	i = 0;
	wut2 = 0;
	if (wut == 0)
	{
		ft_putwstring(str);
		while (str[i])
		{
			count_uni(str[i], count);
			i++;
		}
	}
	while (wut > 0)
	{
		count_uni(str[i], &wut2);
		wut -= wut2;
		if (wut < 0)
			break;
		ft_putwchar(str[i]);
		i++;
		count_uni(str[i], count);
		wut2 = 0;
	}
	while (chunk->field_width > 0)
	{
		*count += 1;
		if (chunk->zero == 1)
			ft_putchar('0');
		else
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

void	step1_string(t_format *chunk, char *str, int *count)
{
	if (chunk->minus == 1)
	{
		string_minus(chunk, str, count);
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
		*count += 1;
		chunk->field_width--;
	}
	if (ft_find_point0(chunk))
		while (chunk->field_width > 0)
		{
			if (chunk->zero == 1)
				ft_putchar('0');
			else
				ft_putchar(' ');
			*count += 1;
			chunk->field_width--;
		}
	else
	{
		*count += (int)ft_strlen(str);
		ft_putstr(str);
	}
}

void	string_minus(t_format *chunk, char *str, int *count)
{
	if ((unsigned long int)chunk->precision < ft_strlen(str) &&
			chunk->precision != 0)
		ft_strnclr(str, chunk->precision);
	ft_putstr(str);
	*count += (int)ft_strlen(str);
	while ((unsigned long int)chunk->field_width > ft_strlen(str))
	{
		ft_putchar(' ');
		*count += 1;
		chunk->field_width--;
	}
}
