/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 12:01:11 by ekiriche          #+#    #+#             */
/*   Updated: 2018/02/03 15:55:49 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	error_handler(t_format *chunk)
{
	if (chunk->conversion == 'x' || chunk->conversion == 'X')
	{
		chunk->plus = 0;
		chunk->space = 0;
	}
	if (chunk->conversion == 's')
	{
		chunk->zero = 0;
		chunk->plus = 0;
		chunk->space = 0;
		chunk->hash = 0;
	}
	if (chunk->conversion == 'c')
	{
		chunk->precision = 0;
		chunk->zero = 0;
		chunk->space = 0;
		chunk->hash = 0;
		chunk->plus = 0;
	}
	if (chunk->space == 1 && chunk->conversion == 'o')
		chunk->space = 0;
	if (chunk->plus == 1 && chunk->conversion == 'o')
		chunk->plus = 0;
	if (chunk->plus == 1 && chunk->space == 1)
		chunk->space = 0;
	if (chunk->zero == 1 && chunk->minus == 1)
		chunk->zero = 0;
}
