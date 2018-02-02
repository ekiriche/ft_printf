/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_xX_start.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 19:53:06 by ekiriche          #+#    #+#             */
/*   Updated: 2018/02/02 20:58:49 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	deal_with_xX(t_format *chunk, va_list arg, int *count)
{
	if (ft_strcmp(chunk->length_flag, "none") == 0)
		deal_with_xX1(chunk, arg, count);
	else if (ft_strcmp(chunk->length_flag, "ll") == 0 ||
			ft_strcmp(chunk->length_flag, "l") == 0 ||
			ft_strcmp(chunk->length_flag, "z") == 0 ||
			ft_strcmp(chunk->length_flag, "j") == 0 ||
			ft_strcmp(chunk->length_flag, "t") == 0)
		deal_with_xX2(chunk, arg, count);
	else if (ft_strcmp(chunk->length_flag, "h") == 0)
		deal_with_xX3(chunk, arg, count);
	else if (ft_strcmp(chunk->length_flag, "hh") == 0)
		deal_with_xX4(chunk, arg, count);
}

void	deal_with_xX(t_format *chunk, va_list arg, int *count)
{
	unsigned int	i;
	char			*ans;

	i = va_arg(arg, int);
	ans = ft_strdup(ft_dectohexsmall((unsigned long int)i));
	
}
