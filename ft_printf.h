/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekiriche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 11:38:17 by ekiriche          #+#    #+#             */
/*   Updated: 2018/02/15 18:01:23 by ekiriche         ###   ########.fr       */
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

typedef struct		s_wut
{
	int				wut1;
	int				wut2;
	int				i;
}					t_wut;

void				norm_wstring3(t_format *chunk, wchar_t *str, t_wut *norm);
void				norm_wstring2(wchar_t *str, int *count, t_wut *norm);
void				norm_wstring(t_format *chunk, wchar_t *str, t_wut *norm,
					int *count);
void				norm_printf2(const char *fmt, t_format *chunk);
void				norm_trouble_maker2(t_format *chunk, int *count, int end);
void				norm_printf(const char *fmt, int *count, t_format *chunk,
					va_list arg);
void				norm_x_minus(t_format *chunk, char *str, int *count);
void				kill_me2(t_format *chunk, char *str, int *count, int lul);
void				norm_x(t_format *chunk, char *str, int *count);
void				count_plus_str(char *str, int *count);
void				norm_deal_x2(t_format *chunk, char *ans, int *c,
					unsigned long long i);
void				norm_di(t_format *chunk, long long *num, int *count);
void				norm_di_minus(t_format *chun, long long *n, int *c, int *f);
void				count_plus_char(char c, int *count);
void				norm_trouble_maker(t_format *chunk);
void				rend_you(t_format *chunk, long long int num, int *count);
void				kill_me(t_format *chunk, char *str, int *count);
void				count_uni(wchar_t c, int *count);
void				holy_crap(t_format *chunk, int *count);
size_t				ft_wstrlen(wchar_t *str);
void				trouble_maker(t_format *chunk, int *count);
void				deal_with_s2(t_format *chunk, va_list arg, int *count);
void				step1_wstring(t_format *chunk, wchar_t *str, int *count);
void				wstring_minus(t_format *chunk, wchar_t *str, int *count);
void				ft_putwstring(wchar_t *str);
void				step1_wchar(t_format *chunk, wchar_t c);
void				wchar_minus(t_format *chunk, wchar_t c);
void				ft_putwchar(wchar_t c);
void				x_int_minus(t_format *chunk, char *str, int *count);
void				deal_with_x(t_format *chunk, va_list arg, int *count);
void				deal_with_x1(t_format *chunk, va_list arg, int *count);
void				deal_with_x2(t_format *chunk, va_list arg, int *count);
void				deal_with_x3(t_format *chunk, va_list arg, int *count);
void				deal_with_x4(t_format *chunk, va_list arg, int *count);
void				step1_x_int(t_format *chunk, char *str, int *count);
void				step1_x_longint(t_format *chunk, char *str);
void				step1_string(t_format *chunk, char *str, int *count);
void				string_minus(t_format *chunk, char *str, int *count);
void				deal_with_s(t_format *chunk, va_list arg, int *count);
void				deal_with_s1(t_format *chunk, va_list arg, int *count);
void				step1_char(t_format *chunk, char c);
void				char_minus(t_format *chunk, char c);
void				deal_with_c(t_format *chunk, va_list arg, int *count);
void				deal_with_c1(t_format *chunk, va_list arg, int *count);
void				deal_with_c2(t_format *chunk, va_list arg, int *count);
void				deal_with_di(t_format *chunk, va_list arg, int *count);
void				deal_with_di1(t_format *chunk, va_list arg, int *count);
void				deal_with_di2(t_format *chunk, va_list arg, int *count);
void				deal_with_di3(t_format *chunk, va_list arg, int *count);
void				deal_with_di4(t_format *chunk, va_list arg, int *count);
void				case_point0(t_format *chunk, int *count);
int					ft_find_point0(t_format *chunk);
void				negative_number_and_zero(t_format *chunk,
					long long int num, int *count);
void				step1_di_longint(t_format *chunk, long long int num,
					int *c);
void				di_longint_minus(t_format *chunk, long long int num,
					int *count);
int					ft_nbrlenlong(long long int num);
void				ft_putnbrlong(long long int num);
void				step1_di_li(t_format *chunk, long long int num, int *count);
void				di_int_minus(t_format *chunk, long long int num, int *coun);
void				ultimate_handler(t_format *chunk, va_list arg, int *count);
void				error_handler(t_format *chunk);
void				step1_di_int(t_format *chunk, long long int num, int *coun);
void				minus_present(t_format *chunk);
void				plus_present(t_format *chunk);
void				zero_present(t_format *chunk);
void				hash_present(t_format *chunk);
void				space_present(t_format *chunk);
int					pepe_pls(char c);
void				look_for_length_flag(t_format *chunk);
void				look_for_field_width(t_format *chunk);
void				look_for_precision(t_format *chunk);
void				do_smth(t_format *chunk);
void				look_for_conversion(t_format *chunk);
int					size_of_chunk(const char *str);
int					ft_printf(char const *fmt, ...);

#endif
