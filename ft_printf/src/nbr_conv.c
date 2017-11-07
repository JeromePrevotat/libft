/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:50:50 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/16 22:50:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	st_conv(t_arg *arg, va_list ap)
{
	arg->argv.imax_arg = (size_t)va_arg(ap, size_t);
	if (arg->conv == 2 && arg->bonus == TRUE)
	{
		binary_conv(arg);
		return ;
	}
	convert(arg);
}

void	ptr_conv(t_arg *arg, va_list ap)
{
	void	*p;
	char	*tmp;

	tmp = NULL;
	p = (void *)va_arg(ap, void *);
	arg->flags.alt_form = TRUE;
	tmp = itoa_base_imax((long)p, 16);
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
