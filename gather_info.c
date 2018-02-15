/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gather_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:21:47 by ekiriche          #+#    #+#             */
/*   Updated: 2018/02/15 16:29:50 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	look_for_length_flag(t_format *chunk)
{
	int	i;

	i = chunk->len_format - 3;
	if (i >= 0)
	{
		if ((chunk->format[i] == 'h' && chunk->format[i + 1] == 'h')
				|| (chunk->format[i] == 'l' && chunk->format[i + 1] == 'l'))
		{
			chunk->length_flag = ft_strsub(chunk->format, i, 2);
			return ;
		}
	}
	i = chunk->len_format - 2;
	if (i >= 0)
	{
		if ((chunk->format[i] == 'h' || chunk->format[i] == 'l'
					|| chunk->format[i] == 'j' || chunk->format[i] == 'z'))
		{
			chunk->length_flag = ft_strsub(chunk->format, i, 1);
			return ;
		}
	}
	chunk->length_flag = ft_strdup("none");
}

void	look_for_field_width(t_format *chunk)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = ft_strdup(chunk->format);
	while (ptr[i] < '1' || ptr[i] > '9')
	{
		if (!(pepe_pls(ptr[i])) || ptr[i] == '.')
		{
			chunk->field_width = 0;
			ft_memdel((void**)&ptr);
			return ;
		}
		i++;
	}
	chunk->field_width = ft_atoi(&ptr[i]);
	ft_memdel((void**)&ptr);
}

void	look_for_conversion(t_format *chunk)
{
	int	i;

	i = 0;
	while (pepe_pls(chunk->format[i]))
		i++;
	if (chunk->format[i] == 'S' || chunk->format[i] == 'C' ||
			chunk->format[i] == 'D' || chunk->format[i] == 'O' ||
			chunk->format[i] == 'U')
	{
		chunk->conversion = ft_tolower(chunk->format[i]);
		if (chunk->length_flag != NULL)
			ft_memdel((void**)&chunk->length_flag);
		chunk->length_flag = ft_strdup("l");
	}
	else if (chunk->format[i] == '%')
		chunk->conversion = '%';
	else
		chunk->conversion = chunk->format[i];
}

void	look_for_precision(t_format *chunk)
{
	char *ptr;
	char *lul;

	ptr = ft_strdup(chunk->format);
	lul = ptr;
	while (*ptr != '.' && pepe_pls(*ptr))
		ptr++;
	if (!(pepe_pls(*ptr)))
	{
		chunk->precision = 0;
		ft_memdel((void**)&lul);
		return ;
	}
	ptr++;
	chunk->precision = ft_atoi(ptr);
	ft_memdel((void**)&lul);
}

int		size_of_chunk(const char *str)
{
	int	len;

	len = 0;
	while (pepe_pls(*str) && *str != '\0')
	{
		len++;
		str++;
	}
	len++;
	return (len);
}
