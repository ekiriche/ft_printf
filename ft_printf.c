#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int		ft_printf(const char *fmt, ...)
{
	va_list arg;
	int	c;
	char	*s;
	//	char	*chunk;
	//	int		size;
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
			printf("%s\n", chunk->format);
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

void	do_smth(t_format *chunk)
{
	chunk->conversion = look_for_conversion(chunk);
	chunk->precision = look_for_precision(chunk);
	printf("%c\n", chunk->conversion);
}

char	look_for_conversion(t_format *chunk)
{
	int	i;

	i = 0;
	while (chunk->format[i] != 's' && chunk->format[i] != 'S' && chunk->format[i] != 'p'
			&& chunk->format[i] != 'd'&& chunk->format[i] != 'D' && chunk->format[i] != 'i' && chunk->format[i] != 'o' && chunk->format[i] != 'O'
			&& chunk->format[i] != 'u' && chunk->format[i] != 'U' && chunk->format[i] != 'x' && chunk->format[i] != 'X'
			&& chunk->format[i] != 'c' && chunk->format[i] != 'C')
		i++;
	return (chunk->format[i]);
}

int		look_for_precision(t_format *chunk)
{
	while (chunk->format
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
	ft_printf("% -10.*d\n%s\n123", "asd");
}
