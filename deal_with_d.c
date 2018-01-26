/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 12:16:10 by ekiriche          #+#    #+#             */
/*   Updated: 2018/01/26 13:29:14 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	deal_with_di(t_format *chunk, va_list arg)
{
	int				i;
//	signed char		c;
//	short int		si;
//	long long int	li;

	if (ft_strcmp(chunk->length_flag, "none") == 0)
	{
		i = va_arg(arg, int);
		step1_di_int(chunk, i);
	}
/*	else if (ft_strcmp(chunk->length_flag, "hh") == 0)
	{
		c = va_arg(arg, signed char);
		step1_di_hh(chunk, c);
	}
	else if (ft_strcmp(chunk->length_flag, "h") == 0)
	{
		si = va_arg(arg, short int);
		step1_di_shortint(chunk, si);
	}
	else if (ft_strcmp(chunk->length_flag, "l") == 0)
	{
		li = va_arg(arg, long long int);
		step1_di_llint(chunk, li);
	} */
}

void	step1_di_int(t_format *chunk, int num)
{
	int flag;

	flag = 0;
	if (chunk->space == 1)
	{
		ft_putchar(' ');
		chunk->field_width--;
	}
//	if (chunk->minus == 1)
//	{
//		step1_di_int_minus;
//		return ;
//	}
	if (chunk->plus == 1 && chunk->precision == 0)
	{
		ft_putchar('+');
		chunk->field_width--;
		flag = 1;
	}
	else if (chunk->plus == 1)
		chunk->field_width--;
	if (chunk->precision < ft_nbrlen(num))
			chunk->precision = ft_nbrlen(num);
	while (chunk->field_width > chunk->precision)
	{
		if (chunk->zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		chunk->field_width--;
	}
	if (chunk->plus == 1 && flag == 0)
		ft_putchar('+');
	while (chunk->precision > ft_nbrlen(num))
	{
		ft_putchar('0');
		chunk->precision--;
	}
	ft_putnbr(num);
}
