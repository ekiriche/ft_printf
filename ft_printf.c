/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 13:41:17 by ekiriche          #+#    #+#             */
/*   Updated: 2018/01/23 14:08:50 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int		ft_printf(const char *fmt, ...)
{
	va_list arg;
	int	c;
	char	*s;
	t_format	*chunk;

	va_start(arg, fmt);
	chunk = malloc(sizeof(t_format));
	while (*fmt != '\0')
	{
		if(*fmt == '%')
		{
			*fmt++;
			chunk->len_format = size_of_chunk(fmt);
			chunk->format = ft_strsub(fmt, 0, chunk->len_format);
			printf("Format: %s\n", chunk->format);
			do_smth(chunk);
			while (chunk->len_format != 0)
			{
				*fmt++;
				chunk->len_format--;
			}
			*fmt++;
			ft_memdel((void**)&chunk->format);

		}
		else
			while (*fmt != '\0' && *fmt != '%')
			{
				write(1, &(*fmt), 1);
				*fmt++;
			}
	}
	va_end(arg);
	return (1);
}

int		pepePls(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X' || c == 'c' || c == 'C')
		return (0);
	return (1);
}

void	do_smth(t_format *chunk)
{
	look_for_conversion(chunk);
	look_for_precision(chunk);
	look_for_field_width(chunk);
	printf("Conversion: %c\n", chunk->conversion);
	printf("Precision: %i\n", chunk->precision);
	printf("Field-width: %i\n", chunk->field_width);
}

void	look_for_field_width(t_format *chunk)
{
	char	*ptr;

	ptr = ft_strdup(chunk->format);
	while (*ptr < '1' || *ptr > '9')
	{
		if (!(pepePls(*ptr)))
		{
			chunk->field_width = -42;
			return ;
		}
		*ptr++;
	}
	chunk->field_width = ft_atoi(ptr);
}

void	look_for_conversion(t_format *chunk)
{
	int	i;

	i = 0;
	while (chunk->format[i] != 's' && chunk->format[i] != 'S' && chunk->format[i] != 'p'
			&& chunk->format[i] != 'd'&& chunk->format[i] != 'D' && chunk->format[i] != 'i' && chunk->format[i] != 'o' && chunk->format[i] != 'O'
			&& chunk->format[i] != 'u' && chunk->format[i] != 'U' && chunk->format[i] != 'x' && chunk->format[i] != 'X'
			&& chunk->format[i] != 'c' && chunk->format[i] != 'C')
		i++;
	chunk->conversion = chunk->format[i];
}

void	look_for_precision(t_format *chunk)
{
	char *ptr;

	ptr = ft_strdup(chunk->format);
	while (*ptr != '.' && pepePls(*ptr))
		*ptr++;
	if (!(pepePls(*ptr)))
	{
		chunk->precision = -42;
		return ;
	}
	*ptr++;
	chunk->precision = ft_atoi(ptr);
}

int		size_of_chunk(const char *str)
{
	int	len;

	len = 0;
	while (*str != 's' && *str != 'S' && *str != 'p' && *str != 'd'
			&& *str != 'D' && *str != 'i' && *str != 'o' && *str != 'O'
			&& *str != 'u' && *str != 'U' && *str != 'x' && *str != 'X'
			&& *str != 'c' && *str != 'C')
	{
		len++;
		*str++;
	}
	len++;
	return (len);
}

int		main()
{
	//	ft_printf("%smamamia %c%c%s%x\n", "rari", 'w', 'a', "tratata", 2147);
	//	printf("%smamamia %c%c%s%x\n", "rari", 'w', 'a', "tratata", 2147);
	//	printf("%D", 0xa);
	//	ft_printf("%%\n");
	//	printf("%hhi\n", 214);
	//	printf("%hd%d", 127, 7500);
	//printf("%#X", 127);
	//	ft_printf("%i %d\n", 033, 033);
	//	printf("%i %d\n", 033, 033);
	//	ft_printf("%x %X\n", 214748364, 214748364);
	//	printf("%x %X\n", 214748364, 214748364);
	//	printf("|%- 10.4d|\n", 42);
	//	printf("|% 010.3hhd|\n", c);
	//	printf("% 10d10", 20);
	//	printf("%.*s", 3, "abcdef");
	ft_printf("%- 322.10d\n%s\n123", "asd");
}
