/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 12:13:31 by ekiriche          #+#    #+#             */
/*   Updated: 2018/02/02 19:54:07 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ultimate_handler(t_format *chunk, va_list arg, int *count)
{
	error_handler(chunk);
	if (chunk->conversion == 'd' || chunk->conversion == 'i')
		deal_with_di(chunk, arg, count);
	if (chunk->conversion == 'o')
		deal_with_o(chunk, arg, count);
	if (chunk->conversion == 'c' || chunk->conversion == '%')
		deal_with_c(chunk, arg, count);
	if (chunk->conversion == 's')
		deal_with_s(chunk, arg, count);
	if (chunk->conversion == 'x' || chunk->conversion == 'X')
		deal_with_xX(chunk, arg, count);
}
