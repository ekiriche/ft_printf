/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 11:38:17 by ekiriche          #+#    #+#             */
/*   Updated: 2018/01/31 16:46:06 by ekiriche         ###   ########.fr       */
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
	int				plus;
	int				minus;
	int				space;
	int				zero;
	int				hash;
}					t_format;

void	case_point0(t_format *chunk);
int		ft_find_point0(t_format *chunk);
void	negative_number_and_zero(t_format *chunk, long long int num);
void	counting(t_format *chunk, long long int li, int *count);
void	step1_di_longint(t_format *chunk, long long int num);
void	di_longint_minus(t_format *chunk, long long int num);
int		ft_nbrlenlong(long long int num);
void	ft_putnbrlong(long long int num);
void	step1_di_li(t_format *chunk, long long int num);
void	di_int_minus(t_format *chunk, int num);
void	ultimate_handler(t_format *chunk, va_list arg, int *count);
void	error_handler(t_format *chunk);
void	deal_with_di(t_format *chunk, va_list arg, int *count);
void	step1_di_int(t_format *chunk, int num);
void	print_smth(t_format *chunk, va_list arg);
void	minus_present(t_format *chunk);
void	plus_present(t_format *chunk);
void	space_present(t_format *chunk);
int		pepePls(char c);
void	look_for_length_flag(t_format *chunk);
void	look_for_field_width(t_format *chunk);
void	look_for_precision(t_format *chunk);
void	do_smth(t_format *chunk);
void	look_for_conversion(t_format *chunk);
int		size_of_chunk(const char *str);
int		ft_printf(char const *fmt, ...);
#endif
