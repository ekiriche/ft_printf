#include "libft.h"

void	ft_dectohex(int n)
{
	int	temp;
	int	i;
	char	ans[100];

	i = -1;
	while (n != 0)
	{
		temp = n % 16;
		if (temp < 10)
			ans[++i] = temp + 48;
		else
			ans[++i] = temp + 55;
		n /= 16;
	}
	while (i >= 0)
	{
		write(1, &ans[i], 1);
		i--;
	}
}
