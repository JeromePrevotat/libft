/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:50:50 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/16 22:50:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	apply_flags(t_arg *arg)
{
	if (arg->flags.zero == TRUE && arg->flags.minus == FALSE
		&& arg->flags.precision == FALSE && arg->type == T_PTR)
		apply_zero(arg);
	if (arg->flags.precision == TRUE && (arg->conv == 16 || arg->conv == 160))
		apply_precision(arg);
	if (arg->flags.alt_form == TRUE)
		apply_alt_form(arg);
	if (arg->flags.precision == TRUE
		&& (arg->conv != 16 && arg->conv != 160 && arg->conv != 0))
		apply_precision(arg);
	if (arg->flags.zero == TRUE && arg->flags.minus == FALSE
		&& arg->flags.precision == FALSE)
		apply_zero(arg);
	else if (arg->flags.zero == TRUE && arg->flags.minus == FALSE
		&& (arg->type == T_CHAR || arg->type == T_WCHAR
		|| arg->type == T_STR || arg->type == T_WSTR || arg->type == 0))
		apply_zero(arg);
	apply_flags_next(arg);
}

void	apply_flags_next(t_arg *arg)
{
	if (arg->flags.space == TRUE && arg->flags.plus != TRUE)
		apply_space(arg);
	if (arg->flags.plus == TRUE)
		apply_plus(arg);
	if (arg->flags.width == TRUE && arg->flags.minus == FALSE
		&& (arg->flags.zero == FALSE || arg->flags.zero != DONE))
		apply_width(arg);
	if (arg->flags.minus == TRUE)
		apply_minus(arg);
}

void	apply_size_flag(t_arg *arg)
{
	if (arg->flags.hh == TRUE)
		apply_hh(arg);
	if (arg->flags.h == TRUE)
		apply_h(arg);
	if (arg->flags.l == TRUE)
		apply_l(arg);
	if (arg->flags.ll == TRUE)
		apply_ll(arg);
	if (arg->flags.j == TRUE)
		apply_j(arg);
	if (arg->flags.z == TRUE)
		apply_z(arg);
}
