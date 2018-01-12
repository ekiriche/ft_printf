#include "libft.h"

void	ft_putunbr(unsigned int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}
