//#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

void		ft_putstr(char *str)
{
	while (*str)
	{
		write(1, &(*str), 1);
		*str++;
	}
}

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putnbr(long long int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}
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
			if (*fmt == 'c')
			{
				c = va_arg(arg, int);
				write(1, &c, 1);
			}
			if (*fmt == 's')
			{
				s = va_arg(arg, char*);
				ft_putstr(s);
			}
			if (*fmt == 'd')
			{
				c = va_arg(arg, int);
				ft_putnbr(c);
			}
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
	ft_printf("%smamamia\n %c%c%s%d", "rari", 'w', 'a', "tratata", 1234567);
	printf("%smamamia\n %c%c%s%d", "rari", 'w', 'a', "tratata", 12345671234567812345678123456789);
}
