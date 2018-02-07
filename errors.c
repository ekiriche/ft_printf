/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 12:01:11 by ekiriche          #+#    #+#             */
/*   Updated: 2018/02/07 15:02:38 by ekiriche         ###   ########.fr       */
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
	char	*ptr;

	ptr = ft_strdup(chunk->format);
	while ((*ptr < '1' || *ptr > '9') && *ptr != '\0' && *ptr != '.')
	{
		if (*ptr == '-')
			chunk->minus = 1;
		if (*ptr == '0')
			chunk->zero = 1;
		ptr++;
	}
	chunk->field_width = ft_atoi(ptr);
	while (*ptr >= '0' && *ptr <= '9')
		ptr++;
	if (*ptr == '.')
	{
		ptr++;
		while (*ptr >= '0' && *ptr <= '9')
			ptr++;
	}
	*count += chunk->field_width - 1;
	*count += (int)ft_strlen(ptr);
	if (chunk->minus == 1)
	{
		ft_putstr(ptr);
		while (chunk->field_width-- - 1 > 0)
		{
			if (chunk->zero == 1)
				ft_putchar('0');
			else
				ft_putchar(' ');
		}
	}
	else
	{
		while (chunk->field_width-- - 1 > 0)
		{
			if (chunk->zero == 1)
				ft_putchar('0');
			else
				ft_putchar(' ');
		}
		ft_putstr(ptr);
	}
}
