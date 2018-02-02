/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_oct_start.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 20:33:41 by ekiriche          #+#    #+#             */
/*   Updated: 2018/02/02 15:45:00 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	deal_with_o(t_format *chunk, va_list arg, int *count)
{
	if (ft_strcmp(chunk->length_flag, "none") == 0)
		deal_with_o1(chunk, arg, count);
	else if (ft_strcmp(chunk->length_flag, "ll") == 0 ||
			ft_strcmp(chunk->length_flag, "l") == 0 ||
			ft_strcmp(chunk->length_flag, "z") == 0 ||
			ft_strcmp(chunk->length_flag, "j") == 0 ||
			ft_strcmp(chunk->length_flag, "t") == 0)
		deal_with_o2(chunk, arg, count);
	else if (ft_strcmp(chunk->length_flag, "h") == 0)
		deal_with_o3(chunk, arg, count);
	else if (ft_strcmp(chunk->length_flag, "hh") == 0)
		deal_with_o4(chunk, arg, count);
}

void	deal_with_o1(t_format *chunk, va_list arg, int *count)
{
	unsigned int	i;

	i = va_arg(arg, unsigned int);
	i = ft_dectooct(i);
	counting(chunk, (long long int)i, count);
	if (ft_find_point0(chunk) && i == 0 && chunk->hash == 0)
	{
		case_point0(chunk);
		return ;
	}
	step1_di_int(chunk, i);
}

void	deal_with_o2(t_format *chunk, va_list arg, int *count)
{
	unsigned long long int	li;

	li = va_arg(arg, unsigned long long int);
	li = ft_dectooctlong(li);
	counting(chunk, li, count);
	if (ft_find_point0(chunk) && li == 0)
	{
		case_point0(chunk);
		return ;
	}
	step1_di_li(chunk, li);
}

void	deal_with_o3(t_format *chunk, va_list arg, int *count)
{
	unsigned short int	i;

	i = va_arg(arg, unsigned int);
	i = ft_dectooct(i);
	counting(chunk, (long long int)i, count);
	if (ft_find_point0(chunk) && i == 0)
	{
		case_point0(chunk);
		return ;
	}
	step1_di_int(chunk, i);
}

void	deal_with_o4(t_format *chunk, va_list arg, int *count)
{
	unsigned char	i;

	i = va_arg(arg, unsigned int);
	i = ft_dectooct(i);
	counting(chunk, (long long int)i, count);
	if (ft_find_point0(chunk) && i == 0)
	{
		case_point0(chunk);
		return ;
	}
	step1_di_int(chunk, i);
}
