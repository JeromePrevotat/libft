/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:50:50 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/16 22:50:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		convert_argv(t_arg *arg, va_list ap)
{
	nb_convert_argv(arg, ap);
	if (char_convert_argv(arg, ap) == -1)
		return (-1);
	return (1);
}

void	nb_convert_argv(t_arg *arg, va_list ap)
{
	if (arg->type == T_SIZET)
		st_conv(arg, ap);
	if (arg->type == T_USHORT)
		ushort_conv(arg, ap);
	if (arg->type == T_SHORT)
		short_conv(arg, ap);
	if (arg->type == T_UINT)
		uint_conv(arg, ap);
	if (arg->type == T_INT)
		int_conv(arg, ap);
	if (arg->type == T_ULONG)
		ulong_conv(arg, ap);
	if (arg->type == T_LONG)
		long_conv(arg, ap);
	if (arg->type == T_ULLONG)
		ullong_conv(arg, ap);
	if (arg->type == T_LLONG)
		llong_conv(arg, ap);
	if (arg->type == T_IMAX)
		imax_conv(arg, ap);
	if (arg->type == T_UIMAX)
		uimax_conv(arg, ap);
}

int		char_convert_argv(t_arg *arg, va_list ap)
{
	if (arg->type == T_UCHAR)
		uchar_conv(arg, ap);
	if (arg->type == T_CHAR)
		char_conv(arg, ap);
	if (arg->type == T_STR)
		str_conv(arg, ap);
	if (arg->type == T_WCHAR)
		if (wchar_conv(arg, ap) == -1)
			return (-1);
	if (arg->type == T_WSTR)
		if (wstr_conv(arg, ap) == -1)
			return (-1);
	if (arg->type == T_PTR)
		ptr_conv(arg, ap);
	return (1);
}

void	convert(t_arg *arg)
{
	int		base;
	char	*tmp;

	tmp = NULL;
	base = arg->conv;
	if (base < 0)
		base = -base;
	if (base > 16 && base != 160)
		base = base / 10;
	if (arg->conv < 0)
		tmp = itoa_base_imax(arg->argv.imax_arg, base);
	else
		tmp = itoa_base_uimax(arg->argv.uimax_arg, base);
	arg->conv_form->len = ft_strlen(tmp);
	if (arg->conv_form->str != NULL)
	{
		free(arg->conv_form->str);
		arg->conv_form->str = NULL;
	}
	arg->conv_form->str = ft_strdup(tmp);
	if (tmp != NULL)
	{
		free(tmp);
		tmp = NULL;
	}
}
