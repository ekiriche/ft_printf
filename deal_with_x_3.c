/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_x_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 14:54:49 by ekiriche          #+#    #+#             */
/*   Updated: 2018/02/15 14:57:50 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	x_int_minus(t_format *chunk, char *str, int *count)
{
	if (chunk->hash == 1 && ft_strcmp(str, "0") != 0 &&
			(chunk->conversion == 'x' || chunk->conversion == 'X'))
		chunk->field_width -= 2;
	if (chunk->hash == 1 && ft_strcmp(str, "0") != 0 &&
			chunk->conversion == 'o')
		chunk->field_width--;
	if (chunk->hash == 1 && ft_strcmp(str, "0") != 0 &&
			chunk->conversion == 'x')
		count_plus_str("0x", count);
	if (chunk->hash == 1 && ft_strcmp(str, "0") != 0 &&
			chunk->conversion == 'X')
		count_plus_str("0X", count);
	if (chunk->hash == 1 && ft_strcmp(str, "0") != 0 &&
			chunk->conversion == 'o')
	{
		chunk->precision--;
		count_plus_char('0', count);
	}
	while (chunk->precision-- > (int)ft_strlen(str))
	{
		count_plus_char('0', count);
		chunk->field_width--;
	}
	norm_x_minus(chunk, str, count);
}

void	norm_x_minus(t_format *chunk, char *str, int *count)
{
	ft_putstr(str);
	*count += (int)ft_strlen(str);
	while (chunk->field_width-- > (int)ft_strlen(str))
		count_plus_char(' ', count);
}
