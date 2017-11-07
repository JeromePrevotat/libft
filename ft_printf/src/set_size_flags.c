/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:50:50 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/16 22:50:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	set_l_flag(t_arg *arg)
{
	if (arg->flags.ll == FALSE)
	{
		arg->flags.l = TRUE;
		return (TRUE);
	}
	return (FALSE);
}

int	set_ll_flag(t_arg *arg)
{
	if (arg->flags.l == TRUE)
		arg->flags.l = FALSE;
	arg->flags.ll = TRUE;
	return (2);
}

int	set_h_flag(t_arg *arg)
{
	if (arg->flags.hh == FALSE)
	{
		arg->flags.h = TRUE;
		return (TRUE);
	}
	return (FALSE);
}

int	set_hh_flag(t_arg *arg)
{
	if (arg->flags.h == TRUE)
		arg->flags.h = FALSE;
	arg->flags.hh = TRUE;
	return (2);
}
