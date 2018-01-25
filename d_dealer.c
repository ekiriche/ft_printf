#include "ft_printf.h"

void	deal_with_di(t_format *chunk, va_list arg)
{
	int		i;
	signed char	c;
	short int	si;
	long long int	li;

	if (ft_strcmp(chunk->length_flag, "none") == 0)
	{
		i = va_arg(arg, int);
		step1_di_int(chunk, i);
	}
	else if (ft_strcmp(chunk->length_flag, "hh") == 0)
	{
		c = va_arg(arg, signed char);
		step1_di_hh(chunk, c);
	}
	else if (ft_strcmp(chunk->length_flag, "h") == 0)
	{
		si = va_arg(arg, short int);
		step1_di_shortint(chunk, si);
	}
	else if (ft_strcmp(chunk->length_flag, "l") == 0)
	{
		li = va_arg(arg, long long int);
		step1_di_llint(chunk, li);
	}
}

void	step1_di_int(t_format *chunk, int n)
{
	if (ft_numlen(n)
}
