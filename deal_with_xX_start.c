/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_xX_start.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 19:53:06 by ekiriche          #+#    #+#             */
/*   Updated: 2018/02/14 18:56:52 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	deal_with_xX(t_format *chunk, va_list arg, int *count)
{
	if (ft_strcmp(chunk->length_flag, "none") == 0 &&
			chunk->conversion != 'p')
		deal_with_xX1(chunk, arg, count);
	else if (ft_strcmp(chunk->length_flag, "ll") == 0 ||
			ft_strcmp(chunk->length_flag, "l") == 0 ||
			ft_strcmp(chunk->length_flag, "z") == 0 ||
			ft_strcmp(chunk->length_flag, "j") == 0 ||
			ft_strcmp(chunk->length_flag, "t") == 0 ||
			chunk->conversion == 'p')
		deal_with_xX2(chunk, arg, count);
	else if (ft_strcmp(chunk->length_flag, "h") == 0)
		deal_with_xX3(chunk, arg, count);
	else if (ft_strcmp(chunk->length_flag, "hh") == 0)
		deal_with_xX4(chunk, arg, count);
}

void	deal_with_xX1(t_format *chunk, va_list arg, int *count)
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
	step1_xX_int(chunk, ans, count);
	ft_memdel((void**)&ans);
}

void	deal_with_xX2(t_format *chunk, va_list arg, int *count)
{
	unsigned long long int	i;
	char					*ans;

	i = va_arg(arg, unsigned long long int);
	if (chunk->conversion == 'x' || chunk->conversion == 'p')
	{
		if (chunk->conversion == 'x')
			ans = ft_dectohexsmall(i);
		else
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
				return ;
			}
			else
			{
				ans = ft_dectohexsmall(i);
				chunk->conversion = 'x';
				chunk->hash = 1;
			}
		}
	}
	else if (chunk->conversion == 'X')
		ans = ft_dectohex(i);
	else if (chunk->conversion == 'u')
		ans = ft_itoa_unsign(i);
	else
		ans = ft_dectooct(i);
	step1_xX_int(chunk, ans, count);
	ft_memdel((void**)&ans);
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
}

void	deal_with_xX3(t_format *chunk, va_list arg, int *count)
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
//	counting_xX(chunk, ans, count);
	step1_xX_int(chunk, ans, count);
	ft_memdel((void**)&ans);
}

void	deal_with_xX4(t_format *chunk, va_list arg, int *count)
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
//	counting_xX(chunk, ans, count);
	step1_xX_int(chunk, ans, count);
	ft_memdel((void**)&ans);
}

void	counting_xX(t_format *chunk, char *str, int *count)
{
	if (chunk->field_width > chunk->precision &&
			chunk->field_width > (int)ft_strlen(str))
		*count += chunk->field_width;
	else if (chunk->precision > (int)ft_strlen(str))
		*count += chunk->precision;
	else if (!(ft_find_point0(chunk) && ft_strcmp(str, "0") == 0))
		*count += (int)ft_strlen(str);
	if (chunk->hash == 1 && chunk->precision == 0 && chunk->field_width == 0 &&
			ft_strcmp(str, "0") != 0 && (chunk->conversion == 'x' ||
				chunk->conversion == 'X'))
		*count += 2;
	if (chunk->hash == 1 && chunk->precision >= (int)ft_strlen(str) &&
	chunk->precision >= chunk->field_width && chunk->conversion != 'u' &&
	chunk->conversion != 'o')
		*count += 2;
	if (chunk->hash == 1 && chunk->precision == 0 && chunk->field_width == 0 &&
			ft_strcmp(str, "0") != 0 && chunk->conversion == 'o')
		*count += 1;
	if (ft_find_point0(chunk) && ft_strcmp(str, "0") == 0 && chunk->hash == 1
			&& chunk->conversion == 'o')
		*count += 1;
}

void	step1_xX_int(t_format *chunk, char *str, int *count)
{
	int flag;

	flag = 0;
	if (ft_find_point0(chunk) && ft_strcmp(str, "0") == 0)
	{
		case_point0(chunk, count);
		return ;
	}
	if (chunk->minus == 1 && chunk->field_width != 0)
	{
		xX_int_minus(chunk, str, count);
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
	if (chunk->hash == 1 && ft_strcmp(str, "0") != 0 &&
			chunk->conversion == 'o')
	{
		chunk->precision--;
		chunk->field_width--;
	}
	if (chunk->precision <= (int)ft_strlen(str))
		chunk->precision = (int)ft_strlen(str);
	while (chunk->field_width-- > chunk->precision)
	{
		*count += 1;
		ft_putchar(' ');
	}
	if (chunk->hash == 1 && ft_strcmp(str, "0") != 0 &&
			chunk->conversion == 'x')
	{
		*count += 2;
		ft_putstr("0x");
	}
	else if (chunk->hash == 1 && ft_strcmp(str, "0") != 0 &&
			chunk->conversion == 'X')
	{
		*count += 2;
		ft_putstr("0X");
	}
	else if (chunk->hash == 1 && ft_strcmp(str, "0") != 0 &&
			chunk->conversion == 'o')
	{
		ft_putchar('0');
		*count += 1;
	}
	while(chunk->precision-- > (int)ft_strlen(str))
	{
		*count += 1;
		ft_putchar('0');
	}
	ft_putstr(str);
	*count += (int)ft_strlen(str);
}

void	xX_int_minus(t_format *chunk, char *str, int *count)
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
