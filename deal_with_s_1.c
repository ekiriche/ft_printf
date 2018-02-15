/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_s_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 18:00:57 by ekiriche          #+#    #+#             */
/*   Updated: 2018/02/15 18:15:22 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	count_uni(wchar_t c, int *count)
{
	if (c > 127 && c <= 2047)
		*count += 2;
	else if (c > 2047 && c <= 65535)
		*count += 3;
	else if (c > 65535)
		*count += 4;
	else if (c <= 127 && c >= 0)
		*count += 1;
}

void	holy_crap(t_format *chunk, int *count)
{
	while (chunk->field_width > 0)
	{
		if (chunk->zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		chunk->field_width--;
		*count += 1;
	}
}

size_t	ft_wstrlen(wchar_t *str)
{
	size_t	i;
	size_t	len;

	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] > 127 && str[i] <= 2047)
			len += 2;
		else if (str[i] > 2047 && str[i] <= 65535)
			len += 3;
		else if (str[i] > 65535)
			len += 4;
		else if (str[i] <= 127)
			len += 1;
		i++;
	}
	return (len);
}

void	step1_string(t_format *chunk, char *str, int *count)
{
	if (chunk->minus == 1)
	{
		string_minus(chunk, str, count);
		return ;
	}
	if ((unsigned long int)chunk->precision < ft_strlen(str) &&
			chunk->precision != 0)
		ft_strnclr(str, chunk->precision);
	while ((unsigned long int)chunk->field_width-- > ft_strlen(str) &&
			!ft_find_point0(chunk))
		if (chunk->zero == 1)
			count_plus_char('0', count);
		else
			count_plus_char(' ', count);
	if (ft_find_point0(chunk))
		while (chunk->field_width-- > 0)
			if (chunk->zero == 1)
				count_plus_char('0', count);
			else
				count_plus_char(' ', count);
	else
	{
		*count += (int)ft_strlen(str);
		ft_putstr(str);
	}
}

void	string_minus(t_format *chunk, char *str, int *count)
{
	if ((unsigned long int)chunk->precision < ft_strlen(str) &&
			chunk->precision != 0)
		ft_strnclr(str, chunk->precision);
	ft_putstr(str);
	*count += (int)ft_strlen(str);
	while ((unsigned long int)chunk->field_width > ft_strlen(str))
	{
		ft_putchar(' ');
		*count += 1;
		chunk->field_width--;
	}
}
