/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_nbr_conv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:50:50 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/16 22:50:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ushort_conv(t_arg *arg, va_list ap)
{
	arg->argv.uimax_arg = (unsigned short)va_arg(ap, int);
	if (arg->conv == 2 && arg->bonus == TRUE)
	{
		binary_conv(arg);
		return ;
	}
	convert(arg);
}

void	uint_conv(t_arg *arg, va_list ap)
{
	arg->argv.uimax_arg = (unsigned int)va_arg(ap, int);
	if (arg->conv == 2 && arg->bonus == TRUE)
	{
		binary_conv(arg);
		return ;
	}
	convert(arg);
}

void	ulong_conv(t_arg *arg, va_list ap)
{
	arg->argv.uimax_arg = (unsigned long)va_arg(ap, long);
	if (arg->conv == 2 && arg->bonus == TRUE)
	{
		binary_conv(arg);
		return ;
	}
	convert(arg);
}

void	ullong_conv(t_arg *arg, va_list ap)
{
	arg->argv.uimax_arg = (unsigned long long)va_arg(ap, long long);
	if (arg->conv == 2 && arg->bonus == TRUE)
	{
		binary_conv(arg);
		return ;
	}
	convert(arg);
}

void	uimax_conv(t_arg *arg, va_list ap)
{
	arg->argv.uimax_arg = (uintmax_t)va_arg(ap, uintmax_t);
	if (arg->conv == 2 && arg->bonus == TRUE)
	{
		binary_conv(arg);
		return ;
	}
	convert(arg);
}
