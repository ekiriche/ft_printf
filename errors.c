/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 12:01:11 by ekiriche          #+#    #+#             */
/*   Updated: 2018/02/11 17:49:34 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	error_handler(t_format *chunk)
{
	if (chunk->conversion == 'x' || chunk->conversion == 'X')
	{
		chunk->plus = 0;
		chunk->space = 0;
	}
//	if (chunk->conversion == 's')
//	{
//		chunk->zero = 0;
//		chunk->plus = 0;
//		chunk->space = 0;
//		chunk->hash = 0;
//	}
//	if (chunk->conversion == 'c')
//	{
//		chunk->precision = 0;
//		chunk->zero = 0;
//		chunk->space = 0;
//		chunk->hash = 0;
//		chunk->plus = 0;
//	}
	if (chunk->space == 1 && chunk->conversion == 'o')
		chunk->space = 0;
	if (chunk->plus == 1 && chunk->conversion == 'o')
		chunk->plus = 0;
	if (chunk->plus == 1 && chunk->space == 1)
		chunk->space = 0;
	if (chunk->zero == 1 && chunk->minus == 1)
		chunk->zero = 0;
}

void	trouble_maker(t_format *chunk, int *count)
{
	int	i;
	int	end;

	i = 0;
	end = (int)ft_strlen(chunk->format);
	while (end > 0)
	{
		if (chunk->format[end - 1] != 'l' && chunk->format[end - 1] != 'h'
		&& chunk->format[end - 1] != 'j' && chunk->format[end - 1] != 'z' &&
		((chunk->format[end - 1] >= 'a' && chunk->format[end - 1] <= 'z') ||
		 (chunk->format[end - 1] >= 'A' && chunk->format[end - 1] <= 'Z')))
		{
			look_for_field_width(chunk);
			*count += chunk->field_width;
			zero_present(chunk);
			minus_present(chunk);
			step1_char(chunk, chunk->format[end - 1]);
			break ;
		}
		end--;
	}
	while (end < (int)ft_strlen(chunk->format))
	{
		ft_putchar(chunk->format[end]);
		*count += 1;
		end++;
	}
}
