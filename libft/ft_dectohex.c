/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 19:14:32 by ekiriche          #+#    #+#             */
/*   Updated: 2018/02/15 12:10:49 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dectohex(unsigned long long int n)
{
	char					*ans;
	unsigned long long int	i;
	unsigned long long int	temp;

	i = 0;
	ans = ft_strnew(100);
	if (n == 0)
		ans[i] = '0';
	while (n != 0)
	{
		if (n % 16 < 10)
			ans[i] = (n % 16) + 48;
		else
			ans[i] = (n % 16) + 55;
		n /= 16;
		i++;
	}
	i = -1;
	while (++i < ft_strlen(ans) / 2)
	{
		temp = ans[i];
		ans[i] = ans[ft_strlen(ans) - 1 - i];
		ans[ft_strlen(ans) - 1 - i] = temp;
	}
	return (ans);
}
