/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_ultis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:50:50 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/16 22:50:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		is_conversion(char c)
{
	char	*conv_tab;
	int		i;

	conv_tab = "sSpdDioOuUxXcC%";
	i = 0;
	while (conv_tab[i] != '\0')
	{
		if (c == conv_tab[i])
			return (TRUE);
		i++;
	}
	if (c == 'b')
		return (TRUE);
	return (FALSE);
}

int		set_flag(t_arg *arg, char c)
{
	if (c == '#')
		return (set_alt_form_flag(arg));
	if (c == '0')
		return (set_zero_flag(arg));
	if (c == '-')
		return (set_minus_flag(arg));
	if (c == '+')
		return (set_plus_flag(arg));
	if (c == 'h')
		return (set_h_flag(arg));
	if (c == 'l')
		return (set_l_flag(arg));
	if (c == 'j')
		return (set_j_flag(arg));
	if (c == 'z')
		return (set_z_flag(arg));
	if (c == 'H')
		return (set_hh_flag(arg));
	if (c == 'L')
		return (set_ll_flag(arg));
	return (FALSE);
}
