/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_s_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 18:01:10 by ekiriche          #+#    #+#             */
/*   Updated: 2018/02/15 18:14:11 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	norm_wstring3(t_format *chunk, wchar_t *str, t_wut *norm)
{
	if (chunk->precision != 0)
	{
		while (chunk->precision > 0 && str[norm->i])
		{
			norm->wut2 = 0;
			count_uni(str[norm->i], &norm->wut1);
			count_uni(str[norm->i], &norm->wut2);
			if (chunk->precision - norm->wut1 < 0)
			{
				norm->wut1 -= norm->wut2;
				break ;
			}
			norm->i++;
		}
		chunk->field_width -= norm->wut1;
	}
	if (norm->wut1 == 0)
		chunk->field_width -= ft_wstrlen(str);
}

void	norm_wstring2(wchar_t *str, int *count, t_wut *norm)
{
	if (norm->wut1 == 0)
	{
		ft_putwstring(str);
		while (str[norm->i])
		{
			count_uni(str[norm->i], count);
			norm->i++;
		}
	}
	while (norm->wut1 > 0)
	{
		count_uni(str[norm->i], &norm->wut2);
		norm->wut1 -= norm->wut2;
		if (norm->wut1 < 0)
			break ;
		ft_putwchar(str[norm->i]);
		count_uni(str[norm->i], count);
		norm->i++;
		norm->wut2 = 0;
	}
}

void	norm_wstring(t_format *chunk, wchar_t *str, t_wut *norm, int *count)
{
	if (chunk->precision != 0)
	{
		while (chunk->precision > 0 && str[norm->i])
		{
			norm->wut2 = 0;
			count_uni(str[norm->i], &norm->wut1);
			count_uni(str[norm->i], &norm->wut2);
			if (chunk->precision - norm->wut1 < 0)
			{
				norm->wut1 -= norm->wut2;
				break ;
			}
			norm->i++;
		}
		chunk->field_width -= norm->wut1;
	}
	if (norm->wut1 == 0)
		chunk->field_width -= ft_wstrlen(str);
	while (chunk->field_width-- > 0)
		if (chunk->zero == 1)
			count_plus_char('0', count);
		else
			count_plus_char(' ', count);
}
