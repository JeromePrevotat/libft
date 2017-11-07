/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:50:50 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/16 22:50:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		fill_arg(t_arg *arg, va_list ap)
{
	set_type_arg(arg);
	set_conv_arg(arg);
	apply_size_flag(arg);
	if (arg->bonus == FALSE)
	{
		if (convert_argv(arg, ap) == -1)
			return (-1);
		apply_flags(arg);
	}
	else
	{
		convert_bonus(arg, ap);
		apply_flags_bonus(arg);
	}
	return (1);
}

void	set_type_arg(t_arg *arg)
{
	char	c;

	c = arg->str_form[ft_strlen(arg->str_form) - 1];
	if (c == 'd' || c == 'i')
		arg->type = T_INT;
	if (c == 'o' || c == 'u' || c == 'x' || c == 'X')
		arg->type = T_UINT;
	if (c == 'D')
		arg->type = T_LONG;
	if (c == 'O' || c == 'U')
		arg->type = T_ULONG;
	if (c == 'c')
		arg->type = T_CHAR;
	if (c == 'C')
		arg->type = T_WCHAR;
	if (c == 's')
		arg->type = T_STR;
	if (c == 'S')
		arg->type = T_WSTR;
	if (c == '%')
		arg->type = T_CHAR;
	if (c == 'p')
		arg->type = T_PTR;
	if (c == 'b')
		bonus_conv(arg);
}

void	set_conv_arg(t_arg *arg)
{
	char	c;

	c = arg->str_form[ft_strlen(arg->str_form) - 1];
	set_nb_conv_arg(arg, c);
	set_char_conv_arg(arg, c);
}

void	set_nb_conv_arg(t_arg *arg, char c)
{
	if (c == 'd' || c == 'i')
		arg->conv = -10;
	if (c == 'D')
		arg->conv = -100;
	if (c == 'o')
		arg->conv = 8;
	if (c == 'O')
		arg->conv = 80;
	if (c == 'u')
		arg->conv = 10;
	if (c == 'U')
		arg->conv = 100;
	if (c == 'x')
		arg->conv = 16;
	if (c == 'X')
		arg->conv = 160;
	if (c == 'b')
		arg->conv = 2;
}

void	set_char_conv_arg(t_arg *arg, char c)
{
	if (c == 'c')
		arg->conv = 2;
	if (c == 'C')
		arg->conv = 20;
	if (c == 's')
		arg->conv = 3;
	if (c == 'S')
		arg->conv = 30;
	if (c == 'p')
		arg->conv = 4;
	if (c == '%')
		arg->conv = '%';
}
