/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costili.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 14:58:38 by ekiriche          #+#    #+#             */
/*   Updated: 2018/01/31 16:08:01 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	negative_number_and_zero(t_format *chunk, long long int num)
{
	if (chunk->precision == 0 && chunk->field_width == 0)
	{
		ft_putnbrlong(num);
		return ;
	}
	num = -num;
	if (chunk->precision == 0 && chunk->field_width > ft_nbrlen(num))
	{
		chunk->precision = chunk->field_width;
		chunk->field_width = 0;
		if (chunk->precision < ft_nbrlenlong(num))
			chunk->precision = ft_nbrlenlong(num);
	}
	ft_putchar('-');
	if (chunk->zero == 1 && chunk->precision > chunk->field_width)
		chunk->precision--;
	else if (chunk->field_width > chunk->precision)
		chunk->field_width--;
	while (chunk->field_width-- > chunk->precision)
		ft_putchar(' ');
	if (chunk->space == 1)
		ft_putchar(' ');
//	ft_putchar('-');
	while (chunk->precision-- > ft_nbrlenlong(num))
		ft_putchar('0');
	ft_putnbrlong(num);
}
