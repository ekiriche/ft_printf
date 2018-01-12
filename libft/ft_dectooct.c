#include "libft.h"

int	ft_dectooct(int num)
{
	int	ans;
	int	temp;
	int	i;

	i = 1;
	ans = 0;
	while (num != 0)
	{
		temp = num % 8;
		num /= 8;
		ans += temp * i;
		i *= 10;
	}
	return (ans);
}
