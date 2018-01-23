/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 11:38:17 by ekiriche          #+#    #+#             */
/*   Updated: 2018/01/23 15:26:15 by ekiriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct		s_format
{
	int				len_format;
	char			*format;
	int				precision;
	int				field_width;
	char			conversion;
	char			*length_flag;
	char			*other;
}					t_format;

int		pepePls(char c);
void	look_for_length_flag(t_format *chunk);
void	look_for_field_width(t_format *chunk);
void	look_for_precision(t_format *chunk);
void	do_smth(t_format *chunk);
void	look_for_conversion(t_format *chunk);
int		size_of_chunk(const char *str);
int		ft_printf(char const *fmt, ...);
void		ultimate_handler(char c, va_list arg);
#endif
