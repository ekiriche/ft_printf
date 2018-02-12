/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 18:04:52 by ekiriche          #+#    #+#             */
/*   Updated: 2018/02/12 14:53:55 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbrlen(int n)
{
	int	len;
	int	temp;

	temp = n;
	len = 1;
	if (temp < 0)
	{
		len++;
		temp = -temp;
	}
	while (temp / 10 > 0)
	{
		temp /= 10;
		len++;
	}
	return (len);
}
