/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 12:16:10 by ekiriche          #+#    #+#             */
/*   Updated: 2018/01/29 18:04:15 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	deal_with_di(t_format *chunk, va_list arg, int *count)
{
	int				i;
	long long int	li;
	short int		si;
	signed char		ci;

	if (ft_strcmp(chunk->length_flag, "none") == 0)
	{
		i = va_arg(arg, int);
		li = (long long int)i;
		if (chunk->field_width > chunk->precision)
			*count += chunk->field_width;
		else if (chunk->precision > ft_nbrlenlong(li))
			*count += chunk->precision;
		else
			*count += ft_nbrlenlong(li);
		if (chunk->plus == 1 && i >= 0 && chunk->field_width < ft_nbrlen(i))
			*count += 1;
		step1_di_int(chunk, i);
	}
	else if (ft_strcmp(chunk->length_flag, "ll") == 0 ||
			ft_strcmp(chunk->length_flag, "l") == 0 ||
			ft_strcmp(chunk->length_flag, "z") == 0 ||
			ft_strcmp(chunk->length_flag, "j") == 0 ||
			ft_strcmp(chunk->length_flag, "t") == 0)
	{
		li = va_arg(arg, long long int);;
		if (chunk->field_width > chunk->precision)
			*count += chunk->field_width;
		else if (chunk->precision > ft_nbrlenlong(li))
			*count += chunk->precision;
		else
			*count += ft_nbrlenlong(li);
		if (chunk->plus == 1 && li >= 0 && chunk->field_width < ft_nbrlenlong(li))
			*count += 1;
		step1_di_li(chunk, li);
	}
	else if (ft_strcmp(chunk->length_flag, "h") == 0)
	{
		si = va_arg(arg, int);
		li = (long long int)si;
		if (chunk->field_width > chunk->precision)
			*count += chunk->field_width;
		else if (chunk->field_width < chunk->precision)
			*count += chunk->precision;
		else
			*count += ft_nbrlenlong(li);
		if (chunk->plus == 1 && si >= 0)
			*count += 1;
		step1_di_int(chunk, si);
	}
	else if (ft_strcmp(chunk->length_flag, "hh") == 0)
	{
		ci = va_arg(arg, int);
		li = (long long int)ci;
		if (chunk->field_width > chunk->precision)
			*count += chunk->field_width;
		else if (chunk->field_width < chunk->precision)
			*count += chunk->precision;
		else
			*count += ft_nbrlenlong(li);
		if (chunk->plus == 1 && ci >= 0)
			*count += 1;
		step1_di_int(chunk, ci);
	}
}

void	step1_di_si(t_format *chunk, short int num)
{
	if (chunk->minus == 1 && chunk->field_width != 0)
	{
		di_int_minus_si(chunk, num);
		return ;
	}
	if (chunk->plus == 1 || chunk->space == 1)
		chunk->field_width--;
	if (chunk->zero == 1 && chunk->precision == 0 && chunk->field_width > ft_nbrlen(num))
	{
		chunk->precision = chunk->field_width;
		chunk->field_width = 0;
	}
	if (chunk->precision < ft_nbrlen(num))
		chunk->precision = ft_nbrlen(num);
	while (chunk->field_width-- > chunk->precision)
		ft_putchar(' ');
	if (chunk->plus == 1 && num >= 0)
		ft_putchar('+');
	if (chunk->space == 1)
		ft_putchar(' ');
	while (chunk->precision-- > ft_nbrlen(num))
		ft_putchar('0');
	ft_putnbr(num);
}

void	di_int_minus_si(t_format *chunk, short int num)
{
	if (chunk->plus == 1 || chunk->space == 1)
	{
		if (chunk->plus == 1 && num >= 0)
			ft_putchar('+');
		if (chunk->space == 1)
			ft_putchar(' ');
		chunk->field_width--;
	}
	while (chunk->precision > ft_nbrlen(num))
	{
		ft_putchar('0');
		chunk->precision--;
		chunk->field_width--;
	}
	ft_putnbr(num);
	chunk->field_width -= ft_nbrlen(num);
	while (chunk->field_width)
	{
		ft_putchar(' ');
		chunk->field_width--;
	}
}

void	step1_di_li(t_format *chunk, long long int num)
{
	if (chunk->minus == 1 && chunk->field_width != 0)
	{
		di_longint_minus(chunk, num);
		return ;
	}
	if (chunk->plus == 1 || chunk->space == 1)
		chunk->field_width--;
	if (chunk->zero == 1 && chunk->precision == 0 && chunk->field_width > ft_nbrlenlong(num))
	{
		chunk->precision = chunk->field_width;
		chunk->field_width = 0;
	}
	if (chunk->precision < ft_nbrlenlong(num))
		chunk->precision = ft_nbrlenlong(num);
	while (chunk->field_width-- > chunk->precision)
		ft_putchar(' ');
	if (chunk->plus == 1 && num >= 0)
		ft_putchar('+');
	if (chunk->space == 1)
		ft_putchar(' ');
	while (chunk->precision-- > ft_nbrlenlong(num))
		ft_putchar('0');
	ft_putnbrlong(num);
}

void	di_longint_minus(t_format *chunk, long long int num)
{
	if (chunk->plus == 1 || chunk->space == 1)
	{
		if (chunk->plus == 1 && num >= 0)
			ft_putchar('+');
		if (chunk->space == 1)
			ft_putchar(' ');
		chunk->field_width--;
	}
	while (chunk->precision > ft_nbrlenlong(num))
	{
		ft_putchar('0');
		chunk->precision--;
		chunk->field_width--;
	}
	ft_putnbrlong(num);
	chunk->field_width -= ft_nbrlenlong(num);
	while (chunk->field_width)
	{
		ft_putchar(' ');
		chunk->field_width--;
	}
}

void	step1_di_int(t_format *chunk, int num)
{
	if (chunk->minus == 1 && chunk->field_width != 0)
	{
		di_int_minus(chunk, num);
		return ;
	}
	if (chunk->plus == 1 || chunk->space == 1)
		chunk->field_width--;
	if (chunk->zero == 1 && chunk->precision == 0 && chunk->field_width > ft_nbrlen(num))
	{
		chunk->precision = chunk->field_width;
		chunk->field_width = 0;
	}
	if (chunk->precision < ft_nbrlen(num))
		chunk->precision = ft_nbrlen(num);
	while (chunk->field_width-- > chunk->precision)
		ft_putchar(' ');
	if (chunk->plus == 1 && num >= 0)
		ft_putchar('+');
	if (chunk->space == 1)
		ft_putchar(' ');
	while (chunk->precision-- > ft_nbrlen(num))
		ft_putchar('0');
	ft_putnbr(num);
}

void	di_int_minus(t_format *chunk, int num)
{
	if (chunk->plus == 1 || chunk->space == 1)
	{
		if (chunk->plus == 1 && num >= 0)
			ft_putchar('+');
		if (chunk->space == 1)
			ft_putchar(' ');
		chunk->field_width--;
	}
	while (chunk->precision > ft_nbrlen(num))
	{
		ft_putchar('0');
		chunk->precision--;
		chunk->field_width--;
	}
	ft_putnbr(num);
	chunk->field_width -= ft_nbrlen(num);
	while (chunk->field_width)
	{
		ft_putchar(' ');
		chunk->field_width--;
	}
}
