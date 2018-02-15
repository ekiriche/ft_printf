/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_xX_start.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 19:53:06 by ekiriche          #+#    #+#             */
/*   Updated: 2018/02/15 14:47:11 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	deal_with_x(t_format *chunk, va_list arg, int *count)
{
	if (ft_strcmp(chunk->length_flag, "none") == 0 &&
			chunk->conversion != 'p')
		deal_with_x1(chunk, arg, count);
	else if (ft_strcmp(chunk->length_flag, "ll") == 0 ||
			ft_strcmp(chunk->length_flag, "l") == 0 ||
			ft_strcmp(chunk->length_flag, "z") == 0 ||
			ft_strcmp(chunk->length_flag, "j") == 0 ||
			ft_strcmp(chunk->length_flag, "t") == 0 ||
			chunk->conversion == 'p')
		deal_with_x2(chunk, arg, count);
	else if (ft_strcmp(chunk->length_flag, "h") == 0)
		deal_with_x3(chunk, arg, count);
	else if (ft_strcmp(chunk->length_flag, "hh") == 0)
		deal_with_x4(chunk, arg, count);
}

void	deal_with_x1(t_format *chunk, va_list arg, int *count)
{
	unsigned int	i;
	char			*ans;

	i = va_arg(arg, unsigned int);
	if (chunk->conversion == 'x')
		ans = ft_dectohexsmall((unsigned long long int)i);
	else if (chunk->conversion == 'X')
		ans = ft_dectohex((unsigned long long int)i);
	else if (chunk->conversion == 'u')
		ans = ft_itoa_unsign((unsigned long long int)i);
	else
		ans = ft_dectooct((unsigned long long int)i);
	step1_x_int(chunk, ans, count);
	ft_memdel((void**)&ans);
}

void	deal_with_x2(t_format *chunk, va_list arg, int *count)
{
	unsigned long long int	i;
	char					*ans;

	i = va_arg(arg, unsigned long long int);
	ans = NULL;
	if (chunk->conversion == 'x')
		ans = ft_dectohexsmall(i);
	else if (chunk->conversion == 'p')
	{
		norm_deal_x2(chunk, ans, count, i);
		return ;
	}
	else if (chunk->conversion == 'X')
		ans = ft_dectohex(i);
	else if (chunk->conversion == 'u')
		ans = ft_itoa_unsign(i);
	else
		ans = ft_dectooct(i);
	step1_x_int(chunk, ans, count);
	ft_memdel((void**)&ans);
}

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

void	deal_with_x3(t_format *chunk, va_list arg, int *count)
{
	unsigned short int	i;
	char				*ans;

	i = va_arg(arg, unsigned int);
	if (chunk->conversion == 'x')
		ans = ft_strdup(ft_dectohexsmall((unsigned long long int)i));
	else if (chunk->conversion == 'X')
		ans = ft_strdup(ft_dectohex((unsigned long long int)i));
	else if (chunk->conversion == 'u')
		ans = ft_itoa_unsign((unsigned long long int)i);
	else
		ans = ft_dectooct((unsigned long long int)i);
	step1_x_int(chunk, ans, count);
	ft_memdel((void**)&ans);
}

void	deal_with_x4(t_format *chunk, va_list arg, int *count)
{
	unsigned char	i;
	char			*ans;

	i = va_arg(arg, unsigned int);
	if (chunk->conversion == 'x')
		ans = ft_strdup(ft_dectohexsmall((unsigned long long int)i));
	else if (chunk->conversion == 'X')
		ans = ft_strdup(ft_dectohex((unsigned long long int)i));
	else if (chunk->conversion == 'u')
		ans = ft_itoa_unsign((unsigned long long int)i);
	else
		ans = ft_dectooct((unsigned long long int)i);
	step1_x_int(chunk, ans, count);
	ft_memdel((void**)&ans);
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

void	x_int_minus(t_format *chunk, char *str, int *count)
{
	if (chunk->hash == 1 && ft_strcmp(str, "0") != 0 &&
			(chunk->conversion == 'x' || chunk->conversion == 'X'))
		chunk->field_width -= 2;
	if (chunk->hash == 1 && ft_strcmp(str, "0") != 0 &&
			chunk->conversion == 'o')
		chunk->field_width--;
	if (chunk->hash == 1 && ft_strcmp(str, "0") != 0 &&
			chunk->conversion == 'x')
	{
		*count += 2;
		ft_putstr("0x");
	}
	if (chunk->hash == 1 && ft_strcmp(str, "0") != 0 &&
			chunk->conversion == 'X')
	{
		*count += 2;
		ft_putstr("0X");
	}
	if (chunk->hash == 1 &&ft_strcmp(str, "0") != 0 &&
			chunk->conversion == 'o')
	{
		*count += 1;
		chunk->precision--;
		ft_putchar('0');
	}
	while (chunk->precision > (int)ft_strlen(str))
	{
		ft_putchar('0');
		*count += 1;
		chunk->precision--;
		chunk->field_width--;
	}
	ft_putstr(str);
	*count += (int)ft_strlen(str);
	while(chunk->field_width > (int)ft_strlen(str))
	{
		ft_putchar(' ');
		*count += 1;
		chunk->field_width--;
	}
}
