/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costili.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 14:58:38 by ekiriche          #+#    #+#             */
/*   Updated: 2018/02/05 14:22:01 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	negative_number_and_zero(t_format *chunk, long long int num)
{
	if (chunk->space == 1)
	{
		chunk->field_width--;
		ft_putchar(' ');
	}
	if (chunk->plus == 1 && num >= 0)
	{
		ft_putchar('+');
		chunk->field_width--;
	}
	else if (num < 0)
	{
		ft_putchar('-');
		num = -num;
		chunk->field_width--;
	}
	while (chunk->field_width > ft_nbrlenlong(num))
	{
		ft_putchar('0');
		chunk->field_width--;
	}
	ft_putnbr(num);
}
