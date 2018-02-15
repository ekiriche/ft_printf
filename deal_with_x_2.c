/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_x_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 14:54:34 by ekiriche          #+#    #+#             */
/*   Updated: 2018/02/15 16:14:45 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	norm_deal_x2(t_format *chunk, char *ans, int *count,
		unsigned long long i)
{
	if (i == 0)
	{
		if (ft_find_point0(chunk))
			ans = ft_strdup("0x");
		else
			ans = ft_strdup("0x0");
		chunk->hash = 0;
		chunk->conversion = 'x';
		kill_me(chunk, ans, count);
		ft_memdel((void**)&ans);
	}
	else
	{
		ans = ft_dectohexsmall(i);
		chunk->conversion = 'x';
		chunk->hash = 1;
		step1_x_int(chunk, ans, count);
		ft_memdel((void**)&ans);
	}
}

void	kill_me(t_format *chunk, char *str, int *count)
{
	int lul;

	lul = (int)ft_strlen(str);
	if (chunk->zero == 1 && chunk->minus == 0)
		chunk->precision = chunk->field_width - lul + 1;
	if (chunk->minus == 0)
	{
		while (chunk->field_width - lul - chunk->precision > 0)
		{
			ft_putchar(' ');
			chunk->field_width--;
			*count += 1;
		}
		ft_putstr(str);
		*count += (int)ft_strlen(str);
		while (chunk->precision-- - 1 > 0)
		{
			ft_putchar('0');
			*count += 1;
		}
	}
	else
		kill_me2(chunk, str, count, lul);
}

void	kill_me2(t_format *chunk, char *str, int *count, int lul)
{
	ft_putstr(str);
	if (chunk->precision - 1 > 0)
		chunk->field_width++;
	while (chunk->precision - 1 > 0)
	{
		ft_putchar('0');
		*count += 1;
		chunk->precision--;
		chunk->field_width--;
	}
	*count += (int)ft_strlen(str);
	while (chunk->field_width - lul - chunk->precision > 0)
	{
		*count += 1;
		ft_putchar(' ');
		chunk->field_width--;
	}
}

void	step1_x_int(t_format *chunk, char *str, int *count)
{
	if (ft_find_point0(chunk) && ft_strcmp(str, "0") == 0)
	{
		case_point0(chunk, count);
		return ;
	}
	if (chunk->minus == 1 && chunk->field_width != 0)
	{
		x_int_minus(chunk, str, count);
		return ;
	}
	if (chunk->hash == 1 && ft_strcmp(str, "0") != 0 &&
			(chunk->conversion == 'x' || chunk->conversion == 'X'))
		chunk->field_width -= 2;
	if (chunk->zero == 1 && chunk->precision == 0 &&
			chunk->field_width > (int)ft_strlen(str))
	{
		chunk->precision = chunk->field_width;
		chunk->field_width = 0;
	}
	norm_x(chunk, str, count);
}

void	norm_x(t_format *chunk, char *str, int *count)
{
	if (chunk->hash == 1 && ft_strcmp(str, "0") != 0 &&
			chunk->conversion == 'o')
	{
		chunk->precision--;
		chunk->field_width--;
	}
	if (chunk->precision <= (int)ft_strlen(str))
		chunk->precision = (int)ft_strlen(str);
	while (chunk->field_width-- > chunk->precision)
		count_plus_char(' ', count);
	if (chunk->hash == 1 && ft_strcmp(str, "0") != 0 &&
			chunk->conversion == 'x')
		count_plus_str("0x", count);
	else if (chunk->hash == 1 && ft_strcmp(str, "0") != 0 &&
			chunk->conversion == 'X')
		count_plus_str("0X", count);
	else if (chunk->hash == 1 && ft_strcmp(str, "0") != 0 &&
			chunk->conversion == 'o')
		count_plus_char('0', count);
	while (chunk->precision-- > (int)ft_strlen(str))
		count_plus_char('0', count);
	ft_putstr(str);
	*count += (int)ft_strlen(str);
}
