/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectooct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 15:11:24 by ekiriche          #+#    #+#             */
/*   Updated: 2018/02/03 17:46:04 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dectooct(unsigned long long dec)
{
	char	*res;
	int		bits_num;
	int		res_len;
	int		i;

	i = 0;
	bits_num = ft_count_bits(dec);
	res_len = (bits_num % 3 == 0) ? (bits_num / 3) : ((bits_num / 3) + 1);
	res = ft_strnew(res_len);
	while (i < res_len)
	{
		res[i] = (dec & 7) + '0';
		dec = dec >> 3;
		i++;
	}
	ft_strrev(res);
	return (res);
}
