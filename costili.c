/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costili.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 14:58:38 by ekiriche          #+#    #+#             */
/*   Updated: 2018/02/15 14:36:57 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	negative_number_and_zero(t_format *chunk, long long int num, int *count)
{
	if (num >= 0 && chunk->space == 1)
	{
		chunk->field_width--;
		*count += 1;
		ft_putchar(' ');
	}
	if (chunk->plus == 1 && num >= 0)
	{
		count_plus_char('+', count);
		chunk->field_width--;
	}
	else if (num < 0)
	{
		ft_putchar('-');
		*count += 1;
		num = -num;
		chunk->field_width--;
	}
	while (chunk->field_width-- > ft_nbrlenlong(num))
	{
		*count += 1;
		ft_putchar('0');
	}
	ft_putnbrlong(num);
	*count += ft_nbrlenlong(num);
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

void	count_plus_char(char c, int *count)
{
	*count += 1;
	ft_putchar(c);
}

void	count_plus_str(char *str, int *count)
{
	ft_putstr(str);
	*count += 2;
}
