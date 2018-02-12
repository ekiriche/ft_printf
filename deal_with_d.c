/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 12:16:10 by ekiriche          #+#    #+#             */
/*   Updated: 2018/02/12 15:51:50 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	step1_di_li(t_format *chunk, long long int num, int *count)
{

	if (chunk->zero == 1 && chunk->precision == 0)
	{
		negative_number_and_zero(chunk, num, count);
		return ;
	}
	if (chunk->minus == 1 && chunk->field_width != 0)
	{
		di_longint_minus(chunk, num, count);
		return ;
	}
	if (chunk->plus == 1 || (chunk->space == 1 && num >= 0))
		chunk->field_width--;
	if (chunk->precision < ft_nbrlenlong(num))
		chunk->precision = ft_nbrlenlong(num);
	while (chunk->field_width-- > chunk->precision)
	{
		*count += 1;
		ft_putchar(' ');
	}
	if (chunk->plus == 1 && num >= 0)
	{
		*count += 1;
		ft_putchar('+');
	}
	if (chunk->space == 1 && num >= 0)
	{
		*count += 1;
		ft_putchar(' ');
	}
	while (chunk->precision-- > ft_nbrlenlong(num))
	{
		*count += 1;
		ft_putchar('0');
	}
	ft_putnbrlong(num);
	if ((unsigned long long int)num == -9223372036854775808U)
		*count += 20;
	else
		*count += ft_nbrlenlong(num);
}

void	di_longint_minus(t_format *chunk, long long int num, int *count)
{
	if (chunk->plus == 1 && num >= 0)
	{
		*count += 1;
		ft_putchar('+');
		chunk->field_width--;
	}
	if (chunk->space == 1 && num >= 0)
	{
		*count += 1;
		ft_putchar(' ');
		chunk->field_width--;
	}
	while (chunk->precision > ft_nbrlenlong(num))
	{
		ft_putchar('0');
		*count += 1;
		chunk->precision--;
		chunk->field_width--;
	}
	ft_putnbrlong(num);
	if ((unsigned long long int)num == -9223372036854775808U)
		*count += 20;
	else
		*count += ft_nbrlenlong(num);
	chunk->field_width -= ft_nbrlenlong(num);
	while (chunk->field_width > 0)
	{
		ft_putchar(' ');
		*count += 1;
		chunk->field_width--;
	}
}

void	step1_di_int(t_format *chunk, int num, int *count)
{
	int flag;
	int flag2;

	flag = 0;
	flag2 = 0;
	if (chunk->zero == 1 && (chunk->precision == 0))
	{
		negative_number_and_zero(chunk, num, count);
		return ;
	}
	if (chunk->minus == 1 && chunk->field_width != 0)
	{
		di_int_minus(chunk, num, count);
		return ;
	}
	if (chunk->plus == 1 || (chunk->space == 1 && num >= 0))
		chunk->field_width--;
	if (num < 0 && chunk->precision >= ft_nbrlen(num))
		chunk->field_width--;
	if (chunk->precision == ft_nbrlen(num) && num < 0)
		flag = 1;
	if (chunk->precision < ft_nbrlen(num))
	{
		flag2 = 1;
		chunk->precision = ft_nbrlen(num);
	}
	while (chunk->field_width-- > chunk->precision)
	{
		*count += 1;
		ft_putchar(' ');
	}
	if (chunk->space == 1 && num >= 0)
	{
		*count += 1;
		ft_putchar(' ');
	}
	if (chunk->plus == 1 && num >= 0)
	{
		*count += 1;
		ft_putchar('+');
	}
	if (num < 0 && chunk->precision >= ft_nbrlen(num) && !flag2)
	{
		ft_putchar('-');
		num = -num;
		*count += 1;
	}
	while (chunk->precision-- > ft_nbrlen(num))
	{
		*count += 1;
		ft_putchar('0');
	}
//	if (flag == 1)
//		ft_putchar('0');
	ft_putnbr(num);
	*count += ft_nbrlenlong((long long int)num);
}

void	di_int_minus(t_format *chunk, int num, int *count)
{
	if (chunk->plus == 1 && num >= 0)
	{
		*count += 1;
		ft_putchar('+');
		chunk->field_width--;
	}
	if (chunk->space == 1 && num >= 0)
	{
		*count += 1;
		ft_putchar(' ');
		chunk->field_width--;
	}
	if (num < 0 && chunk->precision > ft_nbrlen(num))
	{
		ft_putchar('-');
		*count += 1;
		num = -num;
		chunk->field_width--;
	}
	while (chunk->precision > ft_nbrlen(num))
	{
		ft_putchar('0');
		*count += 1;
		chunk->precision--;
		chunk->field_width--;
	}
	ft_putnbr(num);
	*count += ft_nbrlenlong((long long int)num);
	chunk->field_width -= ft_nbrlen(num);
	while (chunk->field_width > 0)
	{
		ft_putchar(' ');
		*count += 1;
		chunk->field_width--;
	}
}
