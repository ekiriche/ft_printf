#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int		ft_printf(const char *fmt, ...)
{
	va_list arg;
	int	c;
	char	*s;

	va_start(arg, fmt);
	while (*fmt != '\0')
	{
		if(*fmt == '%')
		{
			*fmt++;
			ultimate_handler(*fmt, arg);
			*fmt++;
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
	ft_printf("%x %X\n", 214748364, 214748364);
	printf("%x %X\n", 214748364, 214748364);
}
