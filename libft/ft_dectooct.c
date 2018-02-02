#include "libft.h"

unsigned int	ft_dectooct(unsigned int num)
{
	unsigned int	ans;
	unsigned int	i;

	i = 1;
	ans = 0;
	while (num != 0)
	{
		ans += (num % 8) * i;
		num /= 8;
		i *= 10;
	}
	return (ans);
}
