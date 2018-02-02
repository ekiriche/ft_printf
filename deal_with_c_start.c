/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_c_start.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 15:38:49 by ekiriche          #+#    #+#             */
/*   Updated: 2018/02/02 15:50:25 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	deal_with_c(t_format *chunk, va_list arg, int *count)
{
	if (ft_strcmp(chunk->length_flag, "none") == 0)
		deal_with_c1(chunk, arg, count);
	else if (ft_strcmp(chunk->length_flag, "l") == 0)
		deal_with_c2(chunk, arg, count);
}

void	deal_with_c1(t_format *chunk, va_list arg, int *count)
{
	int	i;

	i = va_arg(arg, int);
	counting(chunk, (long long int)i, count);
	if (ft_find_point0(chunk) && i == 0 && chunk->hash == 0)
	{
		case_point0(chunk);
		return ;
	}
	step1_di_int(chunk, i);
}

void	deal_with_c2(t_format *chunk, va_list arg, int *count)
{
	int	li;

	li = va_arg(arg, int);
	counting(chunk, li, count);
	if (ft_find_point0(chunk) && li == 0)
	{
		case_point0(chunk);
		return ;
	}
	step1_di_li(chunk, li);
}
