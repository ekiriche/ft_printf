#include "ft_printf.h"

void	handle_this(t_format *chunk, va_list arg)
{
	if (chunk->conversion == 'd')
	{
		deal_with_d(chunk, arg);
		return ;
	}
}
