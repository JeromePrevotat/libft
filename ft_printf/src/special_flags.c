/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:50:50 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/16 22:50:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	set_j_flag(t_arg *arg)
{
	arg->flags.j = TRUE;
	return (TRUE);
}

int	set_z_flag(t_arg *arg)
{
	arg->flags.z = TRUE;
	return (TRUE);
}

int	apply_j(t_arg *arg)
{
	if (arg->conv == -10)
		arg->type = T_IMAX;
	if (arg->conv == 8 || arg->conv == 10
		|| arg->conv == 16 || arg->conv == 160 || arg->conv == 2)
		arg->type = T_UIMAX;
	return (TRUE);
}

int	apply_z(t_arg *arg)
{
	if (arg->conv == -10 || arg->conv == 8 || arg->conv == 10
		|| arg->conv == 16 || arg->conv == 160 || arg->conv == 2)
		arg->type = T_SIZET;
	return (TRUE);
}
