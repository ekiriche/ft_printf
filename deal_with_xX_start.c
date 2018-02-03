/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_xX_start.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 19:53:06 by ekiriche          #+#    #+#             */
/*   Updated: 2018/02/03 16:19:56 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	deal_with_xX(t_format *chunk, va_list arg, int *count)
{
	if (ft_strcmp(chunk->length_flag, "none") == 0)
		deal_with_xX1(chunk, arg, count);
	else if (ft_strcmp(chunk->length_flag, "ll") == 0 ||
			ft_strcmp(chunk->length_flag, "l") == 0 ||
			ft_strcmp(chunk->length_flag, "z") == 0 ||
			ft_strcmp(chunk->length_flag, "j") == 0 ||
			ft_strcmp(chunk->length_flag, "t") == 0)
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
		ans = ft_strdup(ft_dectohexsmall((unsigned long long int)i));
	else if (chunk->conversion == 'X')
		ans = ft_strdup(ft_dectohex((unsigned long long int)i));
	else if (chunk->conversion == 'u')
		ans = ft_itoa_unsign((unsigned long long int)i);
	else
		ans = ft_dectooct((unsigned long long int)i);
	counting_xX(chunk, ans, count);
	step1_xX_int(chunk, ans);
}

void	deal_with_xX2(t_format *chunk, va_list arg, int *count)
{
	unsigned long long int	i;
	char					*ans;

	i = va_arg(arg, unsigned long long int);
	if (chunk->conversion == 'x')
		ans = ft_strdup(ft_dectohexsmall(i));
	else if (chunk->conversion == 'X')
		ans = ft_strdup(ft_dectohex(i));
	else if (chunk->conversion == 'u')
		ans = ft_itoa_unsign(i);
	else
		ans = ft_dectooct(i);
	counting_xX(chunk, ans, count);
	step1_xX_int(chunk, ans);
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
	counting_xX(chunk, ans, count);
	step1_xX_int(chunk, ans);
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
	counting_xX(chunk, ans, count);
	step1_xX_int(chunk, ans);
}

void	counting_xX(t_format *chunk, char *str, int *count)
{
	if (chunk->field_width > chunk->precision &&
			chunk->field_width > (int)ft_strlen(str))
		*count += chunk->field_width;
	else if ((size_t)chunk->precision > ft_strlen(str))
		*count += chunk->precision;
	else if (!(ft_find_point0(chunk) && ft_strcmp(str, "0") == 0))
		*count += (int)ft_strlen(str);
	if (chunk->hash == 1 && chunk->precision == 0 && chunk->field_width == 0 &&
			ft_strcmp(str, "0") != 0 && (chunk->conversion == 'x' ||
				chunk->conversion == 'X'))
		*count += 2;
	if (chunk->hash == 1 && chunk->precision == 0 && chunk->field_width == 0 &&
			ft_strcmp(str, "0") != 0 && chunk->conversion == 'o')
		*count += 1;
}

void	step1_xX_int(t_format *chunk, char *str)
{
	if (ft_find_point0(chunk) && ft_strcmp(str, "0") == 0)
	{
		case_point0(chunk);
		return ;
	}
	if (chunk->minus == 1 && chunk->field_width != 0)
	{
		xX_int_minus(chunk, str);
		return ;
	}
	if (chunk->hash == 1 && ft_strcmp(str, "0") != 0 &&
	(chunk->conversion == 'x' || chunk->conversion == 'X'))
		chunk->field_width -= 2;
	if (chunk->hash == 1 && ft_strcmp(str, "0") != 0 &&
	chunk->conversion == 'o')
		chunk->field_width--;
	if (chunk->zero == 1 && chunk->precision == 0 &&
			(size_t)chunk->field_width > ft_strlen(str))
	{
		chunk->precision = chunk->field_width;
		chunk->field_width = 0;
	}
	if ((size_t)chunk->precision < ft_strlen(str))
		chunk->precision = (int)ft_strlen(str);
	while (chunk->field_width-- > chunk->precision)
		ft_putchar(' ');
	if (chunk->hash == 1 && ft_strcmp(str, "0") != 0 &&
			chunk->conversion == 'x')
		ft_putstr("0x");
	else if (chunk->hash == 1 && ft_strcmp(str, "0") != 0 &&
			chunk->conversion == 'X')
		ft_putstr("0X");
	else if (chunk->hash == 1 && ft_strcmp(str, "0") != 0 &&
			chunk->conversion == 'o')
		ft_putchar('0');
	while((size_t)chunk->precision-- > ft_strlen(str))
		ft_putchar('0');
	ft_putstr(str);
}

void	xX_int_minus(t_format *chunk, char *str)
{
	if (chunk->hash == 1 && ft_strcmp(str, "0") != 0 &&
	(chunk->conversion == 'x' || chunk->conversion == 'X'))
		chunk->field_width -= 2;
	if (chunk->hash == 1 && ft_strcmp(str, "0") != 0 &&
			chunk->conversion == 'o')
		chunk->field_width--;
	while ((size_t)chunk->precision > ft_strlen(str))
	{
		ft_putchar('0');
		chunk->precision--;
		chunk->field_width--;
	}
	if (chunk->hash == 1 && ft_strcmp(str, "0") != 0 &&
			chunk->conversion == 'x')
		ft_putstr("0x");
	if (chunk->hash == 1 && ft_strcmp(str, "0") != 0 &&
			chunk->conversion == 'X')
		ft_putstr("0X");
	if (chunk->hash == 1 &&ft_strcmp(str, "0") != 0 &&
			chunk->conversion == 'o')
		ft_putchar('0');
	ft_putstr(str);
	while(chunk->field_width > (int)ft_strlen(str))
	{
		ft_putchar(' ');
		chunk->field_width--;
	}
}
