/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gather_info2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:22:08 by ekiriche          #+#    #+#             */
/*   Updated: 2018/02/15 16:27:50 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	minus_present(t_format *chunk)
{
	int i;

	i = 0;
	while (chunk->format[i] && pepe_pls(chunk->format[i]))
	{
		if (chunk->format[i] == '-')
		{
			chunk->minus = 1;
			return ;
		}
		i++;
	}
	chunk->minus = 0;
}

void	plus_present(t_format *chunk)
{
	int i;

	i = 0;
	while (pepe_pls(chunk->format[i]))
	{
		if (chunk->format[i] == '+')
		{
			chunk->plus = 1;
			return ;
		}
		i++;
	}
	chunk->plus = 0;
}

void	space_present(t_format *chunk)
{
	int i;

	i = 0;
	while (pepe_pls(chunk->format[i]))
	{
		if (chunk->format[i] == ' ')
		{
			chunk->space = 1;
			return ;
		}
		i++;
	}
	chunk->space = 0;
}

void	hash_present(t_format *chunk)
{
	int i;

	i = 0;
	while (pepe_pls(chunk->format[i]))
	{
		if (chunk->format[i] == '#')
		{
			chunk->hash = 1;
			return ;
		}
		i++;
	}
	chunk->hash = 0;
}

void	zero_present(t_format *chunk)
{
	int i;

	i = 0;
	while (chunk->format[i] && pepe_pls(chunk->format[i]))
	{
		if (chunk->format[i] == '.')
		{
			chunk->zero = 0;
			return ;
		}
		if (i == 0 && chunk->format[i] == '0')
		{
			chunk->zero = 1;
			return ;
		}
		else if (chunk->format[i] == '0' &&
				(chunk->format[i - 1] < '0' || chunk->format[i - 1] > '9'))
		{
			chunk->zero = 1;
			return ;
		}
		i++;
	}
	chunk->zero = 0;
}
