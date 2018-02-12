/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costili.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 14:58:38 by ekiriche          #+#    #+#             */
/*   Updated: 2018/02/12 14:29:48 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	negative_number_and_zero(t_format *chunk, long long int num, int *count)
{
	if (chunk->space == 1 && (chunk->field_width - 1 > (int)ft_nbrlenlong(num) || chunk->field_width == 0))
	{
		chunk->field_width--;
		*count += 1;
		ft_putchar(' ');
	}
	if (chunk->plus == 1 && num >= 0)
	{
		*count += 1;
		ft_putchar('+');
		chunk->field_width--;
	}
	else if (num < 0)
	{
		ft_putchar('-');
		*count += 1;
		num = -num;
		chunk->field_width--;
	}
	while (chunk->field_width > ft_nbrlenlong(num))
	{
		*count += 1;
		ft_putchar('0');
		chunk->field_width--;
	}
	ft_putnbrlong(num);
	*count += ft_nbrlenlong(num);
}
