/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 13:41:17 by ekiriche          #+#    #+#             */
/*   Updated: 2018/02/15 16:30:55 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int		ft_printf(const char *fmt, ...)
{
	va_list		arg;
	int			count;
	t_format	*chunk;

	va_start(arg, fmt);
	count = 0;
	chunk = malloc(sizeof(t_format));
	while (*fmt != '\0')
		if (*fmt == '%')
		{
			fmt++;
			norm_printf(fmt, &count, chunk, arg);
			fmt += chunk->len_format;
			ft_memdel((void**)&chunk->format);
			ft_memdel((void**)&chunk->length_flag);
		}
		else
			while (*fmt != '\0' && *fmt != '%')
			{
				count_plus_char(*fmt, &count);
				fmt++;
			}
	ft_memdel((void**)&chunk);
	va_end(arg);
	return (count);
}

void	norm_printf(const char *fmt, int *count, t_format *chunk, va_list arg)
{
	chunk->len_format = size_of_chunk(fmt);
	chunk->format = ft_strsub(fmt, 0, chunk->len_format);
	if (pepe_pls(chunk->format[size_of_chunk(fmt) - 1]))
		trouble_maker(chunk, count);
	else
		ultimate_handler(chunk, arg, count);
}

int		pepe_pls(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || c == 'i'
			|| c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x'
			|| c == 'X' || c == 'c' || c == 'C' || c == '%')
		return (0);
	return (1);
}

void	do_smth(t_format *chunk)
{
	plus_present(chunk);
	space_present(chunk);
	minus_present(chunk);
	hash_present(chunk);
	zero_present(chunk);
	look_for_length_flag(chunk);
	look_for_conversion(chunk);
	look_for_precision(chunk);
	look_for_field_width(chunk);
}
