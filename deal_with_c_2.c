/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_c_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 12:47:52 by ekiriche          #+#    #+#             */
/*   Updated: 2018/02/15 12:49:40 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	step1_char(t_format *chunk, char c)
{
	if (chunk->minus == 1 && chunk->field_width != 0)
	{
		char_minus(chunk, c);
		return ;
	}
	while (chunk->field_width > 1)
	{
		if (chunk->zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		chunk->field_width--;
	}
	ft_putchar(c);
}

void	char_minus(t_format *chunk, char c)
{
	ft_putchar(c);
	while (chunk->field_width > 1)
	{
		ft_putchar(' ');
		chunk->field_width--;
	}
}
