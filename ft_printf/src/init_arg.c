/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:50:50 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/16 22:50:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	init_arg(t_arg *arg)
{
	t_buff *cf;

	cf = NULL;
	if (!(cf = (t_buff *)malloc(1 * sizeof(t_buff))))
		return ;
	arg->bonus = FALSE;
	arg->conv = 0;
	arg->type = 0;
	arg->argv.imax_arg = 0;
	arg->argv.uimax_arg = 0;
	arg->width = 0;
	arg->precision = 0;
	arg->wchar_form = FALSE;
	arg->str_form = NULL;
	arg->conv_form = cf;
	init_buffer(arg->conv_form);
	init_flags_arg(arg);
}

void	init_flags_arg(t_arg *arg)
{
	arg->flags.alt_form = FALSE;
	arg->flags.zero = FALSE;
	arg->flags.minus = FALSE;
	arg->flags.plus = FALSE;
	arg->flags.space = FALSE;
	arg->flags.h = FALSE;
	arg->flags.hh = FALSE;
	arg->flags.l = FALSE;
	arg->flags.ll = FALSE;
	arg->flags.j = FALSE;
	arg->flags.z = FALSE;
	arg->flags.precision = FALSE;
	arg->flags.width = FALSE;
}
