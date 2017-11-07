/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:50:50 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/16 22:50:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	bonus_conv(t_arg *arg)
{
	arg->type = T_INT;
	arg->bonus = TRUE;
	arg->flags.minus = FALSE;
	arg->flags.plus = FALSE;
	arg->flags.precision = FALSE;
	arg->flags.width = FALSE;
	if (arg->flags.alt_form == TRUE)
		arg->flags.zero = FALSE;
}

void	convert_bonus(t_arg *arg, va_list ap)
{
	convert_argv(arg, ap);
}

void	apply_flags_bonus(t_arg *arg)
{
	if (arg->flags.alt_form == TRUE)
		apply_bonus_alt_form(arg);
	if (arg->flags.zero == TRUE)
		apply_bonus_zero(arg);
}

void	apply_bonus_alt_form(t_arg *arg)
{
	if (arg->conv == 2)
		bytes_form(arg);
}

void	apply_bonus_zero(t_arg *arg)
{
	return ;
}
