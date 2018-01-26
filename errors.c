/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 12:01:11 by ekiriche          #+#    #+#             */
/*   Updated: 2018/01/26 12:37:31 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	error_handler(t_format *chunk)
{
	if (chunk->plus == 1 && chunk->space == 1)
	{
		chunk->space = 0;
		printf("Plus > space");
	}
}
