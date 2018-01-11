/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_pow_of_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 15:34:41 by ekiriche          #+#    #+#             */
/*   Updated: 2017/11/04 15:47:10 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_pow_of_2(unsigned int n)
{
	unsigned int rofl;

	if (n > 2147483648)
		return (0);
	if (n == 1 || n == 2)
		return (1);
	rofl = 2;
	while (rofl <= n)
	{
		rofl *= 2;
		if (rofl == n)
			return (1);
	}
	return (0);
}
