#include "ft_printf.h"

void		ultimate_handler(char c, va_list arg)
{
	int		i;
	char		*s;
	unsigned int	j;

	if (c == 'X')
	{
		i = va_arg(arg, int);
		ft_dectohexsmall(i);
	}
	if (c == 'c')
	{
		i = va_arg(arg, int);
		write(1, &i, 1);
	}
	if (c == 'd' || c == 'i')
	{
		i = va_arg(arg, int);
		ft_putnbr(i);
	}
	if (c == 's')
	{
		s = va_arg(arg, char*);
		ft_putstr(s);
	}
	if (c == 'u')
	{
		j = va_arg(arg, unsigned int);
		ft_putunbr(j);
	}
	if (c == 'o')
	{
		i = va_arg(arg, int);
		ft_putnbr(ft_dectooct(i));
	}
	if (c == 'x')
	{
		i = va_arg(arg, int);
		ft_dectohex(i);
	}
	if (c == '%')
		ft_putchar('%');
	else
		return ;
}
