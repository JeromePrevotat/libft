/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:50:50 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/16 22:50:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		set_zero_flag(t_arg *arg)
{
	if (arg->flags.zero == OVERRIDE || arg->flags.precision == TRUE)
	{
		arg->flags.zero = OVERRIDE;
		return (TRUE);
	}
	else
		arg->flags.zero = TRUE;
	arg->flags.width = TRUE;
	return (TRUE);
}
