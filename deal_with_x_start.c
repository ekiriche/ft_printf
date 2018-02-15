/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_xX_start.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 19:53:06 by ekiriche          #+#    #+#             */
/*   Updated: 2018/02/15 14:58:33 by ekiriche         ###   ########.fr       */
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
