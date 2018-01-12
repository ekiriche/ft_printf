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
	ft_printf("%smamamia %c%c%s%u\n", "rari", 'w', 'a', "tratata", 2147483647);
	printf("%smamamia %c%c%s%o\n", "rari", 'w', 'a', "tratata", 2147483647);
//	printf("%D", 0xa);

}
