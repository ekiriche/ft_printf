/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 13:41:17 by ekiriche          #+#    #+#             */
/*   Updated: 2018/02/15 16:18:28 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int		ft_printf(const char *fmt, ...)
{
	va_list arg;
	int count;
	t_format	*chunk;

	va_start(arg, fmt);
	count = 0;
	chunk = malloc(sizeof(t_format));
	while (*fmt != '\0')
		if(*fmt == '%')
		{
			fmt++;
			norm_printf(fmt, &count, chunk, arg);
			fmt += chunk->len_format;
			ft_memdel((void**)&chunk->format);
			ft_memdel((void**)&chunk->length_flag);
		}
		else while (*fmt != '\0' && *fmt != '%')
		{
			count_plus_char(*fmt, &count);
			fmt++;
		}
	ft_memdel((void**)&chunk);
	va_end(arg);
	return (count);
}

void	norm_printf2(const char *fmt, t_format *chunk)
{
	fmt += chunk->len_format;
	ft_memdel((void**)&chunk->format);
	ft_memdel((void**)&chunk->length_flag);
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

void	minus_present(t_format *chunk)
{
	int i;

	i = 0;
	while (chunk->format[i] && pepe_pls(chunk->format[i]))
	{
		if (chunk->format[i] == '-')
		{
			chunk->minus = 1;
			return ;
		}
		i++;
	}
	chunk->minus = 0;
}

void	plus_present(t_format *chunk)
{
	int i;

	i = 0;
	while (pepe_pls(chunk->format[i]))
	{
		if (chunk->format[i] == '+')
		{
			chunk->plus = 1;
			return ;
		}
		i++;
	}
	chunk->plus = 0;
}

void	space_present(t_format *chunk)
{
	int i;

	i = 0;
	while (pepe_pls(chunk->format[i]))
	{
		if (chunk->format[i] == ' ')
		{
			chunk->space = 1;
			return ;
		}
		i++;
	}
	chunk->space = 0;
}

void	hash_present(t_format *chunk)
{
	int i;

	i = 0;
	while (pepe_pls(chunk->format[i]))
	{
		if (chunk->format[i] == '#')
		{
			chunk->hash = 1;
			return ;
		}
		i++;
	}
	chunk->hash = 0;
}

void	zero_present(t_format *chunk)
{
	int i;

	i = 0;
	while (chunk->format[i] && pepe_pls(chunk->format[i]))
	{
		if (chunk->format[i] == '.')
		{
			chunk->zero = 0;
			return ;
		}
		if (i == 0 && chunk->format[i] == '0')
		{
			chunk->zero = 1;
			return ;
		}
		else if (chunk->format[i] == '0' &&
				(chunk->format[i - 1] < '0' || chunk->format[i - 1] > '9'))
		{
			chunk->zero = 1;
			return ;
		}
		i++;
	}
	chunk->zero = 0;
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

void	look_for_length_flag(t_format *chunk)
{
	int	i;

	i = chunk->len_format - 3;

	if (i >= 0)
	{
		if ((chunk->format[i] == 'h' && chunk->format[i + 1] == 'h')
				|| (chunk->format[i] == 'l' && chunk->format[i + 1] == 'l'))
		{
			chunk->length_flag = ft_strsub(chunk->format, i, 2);
			return ;
		}
	}
	i = chunk->len_format - 2;
	if (i >= 0)
	{
		if ((chunk->format[i] == 'h' || chunk->format[i] == 'l'
					|| chunk->format[i] == 'j' || chunk->format[i] == 'z'))
		{
			chunk->length_flag = ft_strsub(chunk->format, i, 1);
			return ;
		}
	}
	chunk->length_flag = ft_strdup("none");
}

void	look_for_field_width(t_format *chunk)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = ft_strdup(chunk->format);
	while (ptr[i] < '1' || ptr[i] > '9')
	{
		if (!(pepe_pls(ptr[i])) || ptr[i] == '.')
		{
			chunk->field_width = 0;
			ft_memdel((void**)&ptr);
			return ;
		}
		i++;
	}
	chunk->field_width = ft_atoi(&ptr[i]);
	ft_memdel((void**)&ptr);
}

void	look_for_conversion(t_format *chunk)
{
	int	i;

	i = 0;
	while (pepe_pls(chunk->format[i]))
		i++;
	if (chunk->format[i] == 'S' || chunk->format[i] == 'C' ||
			chunk->format[i] == 'D' || chunk->format[i] == 'O' ||
			chunk->format[i] == 'U')
	{
		chunk->conversion = ft_tolower(chunk->format[i]);
		if (chunk->length_flag != NULL)
			ft_memdel((void**)&chunk->length_flag);
		chunk->length_flag = ft_strdup("l");
	}
	else if (chunk->format[i] == '%')
		chunk->conversion = '%';
	else
		chunk->conversion = chunk->format[i];
}

void	look_for_precision(t_format *chunk)
{
	char *ptr;
	char *lul;

	ptr = ft_strdup(chunk->format);
	lul = ptr;
	while (*ptr != '.' && pepe_pls(*ptr))
		ptr++;
	if (!(pepe_pls(*ptr)))
	{
		chunk->precision = 0;
		ft_memdel((void**)&lul);
		return ;
	}
	ptr++;
	chunk->precision = ft_atoi(ptr);
	ft_memdel((void**)&lul);
}

int		size_of_chunk(const char *str)
{
	int	len;

	len = 0;
	while (pepe_pls(*str) && *str != '\0')
	{
		len++;
		str++;
	}
	len++;
	return (len);
}
