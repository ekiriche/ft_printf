/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 12:16:10 by ekiriche          #+#    #+#             */
/*   Updated: 2018/02/15 13:13:46 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	rend_you(t_format *chunk, long long int num, int *count)
{
	while (chunk->field_width - 1 > chunk->precision
			&& chunk->field_width - 1 > ft_nbrlen(num))
	{
		ft_putchar(' ');
		*count += 1;
		chunk->field_width--;
	}
	ft_putchar('-');
	num = -num;
	ft_putchar('0');
	chunk->precision--;
	*count += 2;
	while (chunk->precision-- > ft_nbrlenlong(num))
	{
		*count += 1;
		ft_putchar('0');
	}
	ft_putnbrlong(num);
	*count += ft_nbrlenlong(num);
}

void	step1_di_int(t_format *chunk, long long int num, int *count)
{
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
	if (chunk->precision >= ft_nbrlen(num) && num < 0)
	{
		rend_you(chunk, num, count);
		return ;
	}
	norm_di(chunk, &num, count);
	ft_putnbrlong(num);
	if ((unsigned long long int)num == -9223372036854775808U)
		*count += 20;
	else
		*count += ft_nbrlenlong(num);
}

void	norm_di(t_format *chunk, long long *num, int *count)
{
	if ((*num >= 0 && chunk->plus == 1) || (chunk->space == 1 && *num >= 0))
		chunk->field_width--;
	if (*num < 0 && chunk->precision >= ft_nbrlenlong(*num))
		chunk->field_width--;
	if (chunk->precision < ft_nbrlenlong(*num))
		chunk->precision = ft_nbrlenlong(*num);
	while (chunk->field_width-- > chunk->precision)
		count_plus_char(' ', count);
	if (chunk->space == 1 && *num >= 0)
		count_plus_char(' ', count);
	if (chunk->plus == 1 && *num >= 0)
		count_plus_char('+', count);
	if (*num < 0 && chunk->precision > ft_nbrlenlong(*num))
	{
		*num *= -1;
		count_plus_char('-', count);
	}
	while (chunk->precision-- > ft_nbrlenlong(*num))
		count_plus_char('0', count);
}

void	di_int_minus(t_format *chunk, long long int num, int *count)
{
	int flag;

	flag = 0;
	norm_di_minus(chunk, &num, count, &flag);
	ft_putnbrlong(num);
	if ((unsigned long long int)num == -9223372036854775808U)
		*count += 20;
	else
		*count += ft_nbrlenlong(num);
	if (flag == 1)
		chunk->field_width -= ft_nbrlenlong(num) + 1;
	else
		chunk->field_width -= ft_nbrlenlong(num);
	while (chunk->field_width-- > 0)
		count_plus_char(' ', count);
}

void	norm_di_minus(t_format *chunk, long long int *num, int *count,
		int *flag)
{
	if (chunk->plus == 1 && *num >= 0)
	{
		count_plus_char('+', count);
		chunk->field_width--;
	}
	if (chunk->space == 1 && *num >= 0)
	{
		count_plus_char(' ', count);
		chunk->field_width--;
	}
	if (*num < 0 && chunk->precision >= ft_nbrlenlong(*num))
	{
		count_plus_char('-', count);
		count_plus_char('0', count);
		*num *= -1;
		chunk->field_width--;
		*flag = 1;
		chunk->precision--;
	}
	while (chunk->precision-- > ft_nbrlenlong(*num))
	{
		count_plus_char('0', count);
		chunk->field_width--;
	}
}
