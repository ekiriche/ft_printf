/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_s_start.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 17:19:50 by ekiriche          #+#    #+#             */
/*   Updated: 2018/02/15 18:16:59 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	deal_with_s(t_format *chunk, va_list arg, int *count)
{
	if (ft_strcmp(chunk->length_flag, "none") == 0)
		deal_with_s1(chunk, arg, count);
	else if (ft_strcmp(chunk->length_flag, "l") == 0)
		deal_with_s2(chunk, arg, count);
}

void	deal_with_s1(t_format *chunk, va_list arg, int *count)
{
	char	*str;
	void	*lul;

	lul = va_arg(arg, char*);
	if (lul == NULL)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(lul);
	if (ft_find_point0(chunk))
		holy_crap(chunk, count);
	else
		step1_string(chunk, str, count);
	ft_memdel((void**)&str);
}

void	deal_with_s2(t_format *chunk, va_list arg, int *count)
{
	wchar_t	*str;
	char	*str_null;

	str = va_arg(arg, wchar_t*);
	if (str == NULL)
	{
		str_null = ft_strdup("(null)");
		step1_string(chunk, str_null, count);
		ft_memdel((void**)&str_null);
		return ;
	}
	step1_wstring(chunk, str, count);
}

void	step1_wstring(t_format *chunk, wchar_t *str, int *count)
{
	t_wut	*norm;

	if (ft_find_point0(chunk))
	{
		holy_crap(chunk, count);
		return ;
	}
	if (chunk->minus == 1)
	{
		wstring_minus(chunk, str, count);
		return ;
	}
	norm = malloc(sizeof(t_wut));
	norm->wut1 = 0;
	norm->i = 0;
	norm_wstring(chunk, str, norm, count);
	norm->i = 0;
	norm->wut2 = 0;
	norm_wstring2(str, count, norm);
	ft_memdel((void**)&norm);
}

void	wstring_minus(t_format *chunk, wchar_t *str, int *count)
{
	t_wut	*norm;

	norm = malloc(sizeof(t_wut));
	norm->wut1 = 0;
	norm->i = 0;
	norm_wstring3(chunk, str, norm);
	norm->i = 0;
	norm->wut2 = 0;
	norm_wstring2(str, count, norm);
	while (chunk->field_width-- > 0)
		if (chunk->zero == 1)
			count_plus_char('0', count);
		else
			count_plus_char(' ', count);
	ft_memdel((void**)&norm);
}
