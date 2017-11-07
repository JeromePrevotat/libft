/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigend_nbr_conv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:50:50 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/16 22:50:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	short_conv(t_arg *arg, va_list ap)
{
	arg->argv.imax_arg = (short)va_arg(ap, int);
	if (arg->conv == 2 && arg->bonus == TRUE)
	{
		binary_conv(arg);
		return ;
	}
	convert(arg);
}

void	int_conv(t_arg *arg, va_list ap)
{
	arg->argv.imax_arg = (int)va_arg(ap, int);
	if (arg->conv == 2 && arg->bonus == TRUE)
	{
		binary_conv(arg);
		return ;
	}
	convert(arg);
}

void	long_conv(t_arg *arg, va_list ap)
{
	arg->argv.imax_arg = (long)va_arg(ap, long);
	if (arg->conv == 2 && arg->bonus == TRUE)
	{
		binary_conv(arg);
		return ;
	}
	convert(arg);
}

void	llong_conv(t_arg *arg, va_list ap)
{
	arg->argv.imax_arg = (long long)va_arg(ap, long long);
	if (arg->conv == 2 && arg->bonus == TRUE)
	{
		binary_conv(arg);
		return ;
	}
	convert(arg);
}

void	imax_conv(t_arg *arg, va_list ap)
{
	arg->argv.imax_arg = (intmax_t)va_arg(ap, intmax_t);
	if (arg->conv == 2 && arg->bonus == TRUE)
	{
		binary_conv(arg);
		return ;
	}
	convert(arg);
}
