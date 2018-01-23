/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectohexsmall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 11:00:27 by ekiriche          #+#    #+#             */
/*   Updated: 2018/01/23 11:02:32 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void            ft_dectohexsmall(int n)
{
	int     temp;
	int     i;
	char    ans[100];
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
//		if (ans[i] >= '0' && ans[i] <= '9')
			write(1, &ans[i], 1);
//		else
//			ft_putchar(ans[i] + 32);
		i--;
	}
}
