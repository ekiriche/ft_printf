/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 12:13:31 by ekiriche          #+#    #+#             */
/*   Updated: 2018/01/29 15:56:42 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ultimate_handler(t_format *chunk, va_list arg, int *count)
{
	error_handler(chunk);
	if (chunk->conversion == 'd' || chunk->conversion == 'i')
	{
		deal_with_di(chunk, arg, count);
	}
}
