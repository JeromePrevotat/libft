/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 14:59:53 by jprevota          #+#    #+#             */
/*   Updated: 2017/04/24 18:02:45 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define ERROR -1
# define TRUE 1
# define FALSE 0
# define OVERRIDE 3
# define DONE 4

# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define RESET "\x1b[0m"

# include "./libft.h"
# include <stdarg.h>
# include <wchar.h>
# include <inttypes.h>
# include <limits.h>
# include <locale.h>

typedef struct		s_buff
{
	char			*str;
	size_t			len;
}					t_buff;

typedef struct		s_flags
{
	int				alt_form;
	int				zero;
	int				minus;
	int				plus;
	int				space;
	int				h;
	int				hh;
	int				l;
	int				ll;
	int				j;
	int				z;
	int				precision;
	int				width;
}					t_flags;

typedef union		u_argv
{
	void			*ptr;
	int				i_arg;
	long			l_arg;
	long long		ll_arg;
	uintmax_t		uimax_arg;
	intmax_t		imax_arg;
	unsigned char	uc_arg;
	char			c_arg;
	char			*str_arg;
	wchar_t			wchar_arg;
	wchar_t			*wstr_arg;
}					t_argv;

typedef struct		s_argument
{
	t_argv			argv;
	t_flags			flags;
	int				type;
	int				conv;
	int				width;
	int				precision;
	char			*str_form;
	t_buff			*conv_form;
	int				wchar_form;
	int				bonus;
}					t_arg;

enum
{
	T_SIZET, T_USHORT, T_SHORT, T_UINT, T_INT, T_ULONG, T_LONG,
	T_ULLONG, T_LLONG, T_IMAX, T_UIMAX,
	T_UCHAR, T_CHAR, T_STR, T_WCHAR, T_WSTR, T_PTR
};

//Ft_printf.c
int					ft_printf(const char *format, ...);
int					get_arg_str_form(char *format, t_arg *arg, va_list ap);

//Cat_functions.c
int					cat_format(char *format, va_list ap);
void				reset_arg(t_arg *arg);
void				free_ressources(t_arg *arg, t_buff *buff);
int					end(t_buff *buff, t_arg *arg);

//Flags_parsing.c
int					new_flag_parsing(t_arg *arg, char *format, size_t i);
int					new_check_flags_a(t_arg *arg, char *format, size_t i);
int					new_check_flags_b(t_arg *arg, char *format, size_t i);

//Parsing_utils.c
int					is_conversion(char c);
int					set_flag(t_arg *arg, char c);

//Apply_flags.c
void				apply_flags(t_arg *arg);
void				apply_flags_next(t_arg *arg);
void				apply_size_flag(t_arg *arg);

//Undefined_behaviour.c
char				*get_undefined_behaviour(t_arg *arg);
int					ub_is_flag(char c, t_arg *arg);

//Init_arg.c
void				init_flags_arg(t_arg *arg);
void				init_arg(t_arg *arg);

//Fill_arg.c
int					fill_arg(t_arg *arg, va_list ap);
void				set_type_arg(t_arg *arg);
void				set_conv_arg(t_arg *arg);
void				set_nb_conv_arg(t_arg *arg, char c);
void				set_char_conv_arg(t_arg *arg, char c);

//Convert.c
int					convert_argv(t_arg *arg, va_list ap);
void				nb_convert_argv(t_arg *arg, va_list ap);
int					char_convert_argv(t_arg *arg, va_list ap);
void				convert(t_arg *arg);

//Special_flags.c
int					set_j_flag(t_arg *arg);
int					set_z_flag(t_arg *arg);
int					apply_j(t_arg *arg);
int					apply_z(t_arg *arg);

//Set_size_flags.c
int					set_l_flag(t_arg *arg);
int					set_ll_flag(t_arg *arg);
int					set_h_flag(t_arg *arg);
int					set_hh_flag(t_arg *arg);

//Set_form_flags.c
int					set_alt_form_flag(t_arg *arg);
int					set_zero_flag(t_arg *arg);
int					set_minus_flag(t_arg *arg);
int					set_plus_flag(t_arg *arg);
int					set_space_flag(t_arg *arg, char *format, int j);

//Apply_size_flags.c
int					apply_l(t_arg *arg);
int					apply_ll(t_arg *arg);
int					apply_h(t_arg *arg);
int					apply_hh(t_arg *arg);

//Apply_form_flags.c
int					apply_alt_form(t_arg *arg);
int					apply_minus(t_arg *arg);
int					apply_plus(t_arg *arg);
int					apply_space(t_arg *arg);

//Width.c
int					set_width(t_arg *arg, char *str_form);
void				apply_width(t_arg *arg);
int					get_str_with(t_arg *arg);

//Precision.c
int					set_precision(t_arg *arg, char *str_form);
void				apply_precision(t_arg *arg);
void				apply_str_pre(t_arg *arg);
void				apply_pre_zero(t_arg *arg);

//Apply_nbr_pre.c
void				apply_nbr_pre(t_arg *arg);
char				*apply_negative(t_arg *arg);
char				*apply_positive(t_arg *arg);

//Apply_ptr_pre.c
char				*apply_ptr_precision(t_arg *arg);
char				*ptr_pre(t_arg *arg, int real_pre);

//Zero_flag.c
int					set_zero_flag(t_arg *arg);

//Apply_zero.c
void				apply_zero(t_arg *arg);
void				apply_str_zero(t_arg *arg);
char				*apply_nbr_zero(t_arg *arg, int real_width);
void				apply_zero_hex_altform(t_arg *arg);
int					get_zero_width(t_arg *arg);

//Nbr_conv.c
void				st_conv(t_arg *arg, va_list ap);
void				ptr_conv(t_arg *arg, va_list ap);

//Unsigned_nbr_conv.c
void				ushort_conv(t_arg *arg, va_list ap);
void				uint_conv(t_arg *arg, va_list ap);
void				ulong_conv(t_arg *arg, va_list ap);
void				ullong_conv(t_arg *arg, va_list ap);
void				uimax_conv(t_arg *arg, va_list ap);

//Signed_nbr_conv.c
void				short_conv(t_arg *arg, va_list ap);
void				int_conv(t_arg *arg, va_list ap);
void				long_conv(t_arg *arg, va_list ap);
void				llong_conv(t_arg *arg, va_list ap);
void				imax_conv(t_arg *arg, va_list ap);

//Char_conv.c
void				uchar_conv(t_arg *arg, va_list ap);
void				char_conv(t_arg *arg, va_list ap);
void				str_conv(t_arg *arg, va_list ap);
int					wchar_conv(t_arg *arg, va_list ap);
int					wstr_conv(t_arg *arg, va_list ap);

//R_value.c
int					check_ret(t_arg *arg);

//Itoa.c
char				*itoa_base_uimax(uintmax_t n, int base);
char				*itoa_base_imax(intmax_t n, int base);

//Utils.c
char				*str_memcat(char *mem1, char *mem2, size_t size, int del);
void				sfree(char *mem1, char *mem2, int del);
int					get_width(char *str, t_arg *arg);
int					argv_sign(t_arg *arg);

/*
** Wchar_functions.c
*/
size_t				ft_wstr_blen(const wchar_t *str);
size_t				ft_wstr_clen(const wchar_t *wstr);
char				*wstr_to_str(t_arg *arg, wchar_t *wstr);
int					wchar_to_char(wchar_t wchar, char *str);
int					convert_wchar(wchar_t wchar, char *str);

//Buff.c
void				init_buffer(t_buff *buff);
void				write_buffer(t_buff *buff);
void				cat_buffer(t_buff *buff, t_arg *arg);
void				cat_str_buffer(t_buff *buff, char *src, size_t size);

//Bonus.c
void				bonus_conv(t_arg *arg);
void				convert_bonus(t_arg *arg, va_list ap);
void				apply_flags_bonus(t_arg *arg);
void				apply_bonus_alt_form(t_arg *arg);
void				apply_bonus_zero(t_arg *arg);

//Binary_conv.c
void				binary_conv(t_arg *arg);
char				*cmp2(t_arg *arg, int base);
int					get_len(t_arg *arg);
char				*strrev(char *str);

//Bytes_form.c
void				bytes_form(t_arg *arg);
char				*apply_bytes_form(t_arg *arg);

#endif
