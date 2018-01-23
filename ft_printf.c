/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 13:41:17 by ekiriche          #+#    #+#             */
/*   Updated: 2018/01/23 17:27:28 by ekiriche         ###   ########.fr       */
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
			fmt++;
			chunk->len_format = size_of_chunk(fmt);
			chunk->format = ft_strsub(fmt, 0, chunk->len_format);
			printf("Format: %s\n", chunk->format);
			printf("Len: %i\n", chunk->len_format);
			do_smth(chunk);
			printf("\n");
			while (chunk->len_format != 0)
			{
				fmt++;
				chunk->len_format--;
			}
			ft_memdel((void**)&chunk->format);

		}
		else
			while (*fmt != '\0' && *fmt != '%')
			{
				write(1, &(*fmt), 1);
				fmt++;
			}
	}
	va_end(arg);
	return (1);
}

int		pepePls(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || c == 'i'
			|| c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x'
			|| c == 'X' || c == 'c' || c == 'C')
		return (0);
	return (1);
}

void	minus_present(t_format *chunk)
{
	int i;

	i = 0;
	while (pepePls(chunk->format[i]))
	{
		if (chunk->format[i] == '-')
		{
			chunk->minus = 1;
			return ;
		}
		i++;
	}
	chunk->minus = -42;
}

void	plus_present(t_format *chunk)
{
	int i;

	i = 0;
	while (pepePls(chunk->format[i]))
	{
		if (chunk->format[i] == '+')
		{
			chunk->plus = 1;
			return ;
		}
		i++;
	}
	chunk->plus = -42;
}

void	space_present(t_format *chunk)
{
	int i;

	i = 0;
	while (pepePls(chunk->format[i]))
	{
		if (chunk->format[i] == ' ')
		{
			chunk->space = 1;
			return ;
		}
		i++;
	}
	chunk->space = -42;
}

void	hash_present(t_format *chunk)
{
	int i;

	i = 0;
	while (pepePls(chunk->format[i]))
	{
		if (chunk->format[i] == '#')
		{
			chunk->hash = 1;
			return ;
		}
		i++;
	}
	chunk->hash = -42;
}

void	zero_present(t_format *chunk)
{
	int i;

	i = 0;
	while (pepePls(chunk->format[i]))
	{
		if (i == 0 && chunk->format[i] == '0')
		{
			chunk->zero = 1;
			return ;
		}
		else if (chunk->format[i] == '0' && (chunk->format[i - 1] < '1' || chunk->format[i - 1] > '9'))
		{
			chunk->zero = 1;
			return ;
		}
		i++;
	}
}

void	do_smth(t_format *chunk)
{
	look_for_conversion(chunk);
	look_for_precision(chunk);
	look_for_field_width(chunk);
	look_for_length_flag(chunk);
	plus_present(chunk);
	space_present(chunk);
	minus_present(chunk);
	hash_present(chunk);
	zero_present(chunk);
	printf("Minus: %i\n", chunk->minus);
	printf("Space: %i\n", chunk->space);
	printf("Plus: %i\n", chunk->plus);
	printf("Zero: %i\n", chunk->zero);
	printf("Hash: %i\n", chunk->hash);
	printf("Conversion: %c\n", chunk->conversion);
	printf("Precision: %i\n", chunk->precision);
	printf("Field-width: %i\n", chunk->field_width);
	printf("Length flag: %s\n", chunk->length_flag);
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

	ptr = ft_strdup(chunk->format);
	while (*ptr < '1' || *ptr > '9')
	{
		if (!(pepePls(*ptr)))
		{
			chunk->field_width = -42;
			return ;
		}
		ptr++;
	}
	chunk->field_width = ft_atoi(ptr);
}

void	look_for_conversion(t_format *chunk)
{
	int	i;

	i = 0;
	while (pepePls(chunk->format[i]))
		i++;
	chunk->conversion = chunk->format[i];
}

void	look_for_precision(t_format *chunk)
{
	char *ptr;

	ptr = ft_strdup(chunk->format);
	while (*ptr != '.' && pepePls(*ptr))
		ptr++;
	if (!(pepePls(*ptr)))
	{
		chunk->precision = -42;
		return ;
	}
	ptr++;
	chunk->precision = ft_atoi(ptr);
}

int		size_of_chunk(const char *str)
{
	int	len;

	len = 0;
	while (pepePls(*str))
	{
		len++;
		str++;
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
	//		printf("|%- 10.4d|\n", 42);
	//	printf("|% 010.3hhd|\n", c);
	//	printf("% 10d10", 20);
	//	printf("%.*s", 3, "abcdef");
	//ft_printf("%- 322.10d\n%s\n123", "asd");
	//	printf("%+010d", 12345);
	//ft_printf("%+10.4lld%s%hd", "ads");
	ft_printf("%+-# 010.43lld", 123);
}
