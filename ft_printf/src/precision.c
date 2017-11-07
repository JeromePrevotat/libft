/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:50:50 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/16 22:50:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		set_precision(t_arg *arg, char *str_form)
{
	size_t	i;
	char	*precision;
	int		next_i;

	i = 0;
	next_i = 1;
	if (!(precision = (char *)malloc((ft_strlen(str_form) + 1) * sizeof(char))))
		return (FALSE);
	ft_memset(precision, '\0', ft_strlen(str_form) + 1);
	while (i < ft_strlen(str_form) && ft_isdigit(str_form[i]) == TRUE)
	{
		precision[i] = str_form[i];
		i++;
	}
	precision[i] = '\0';
	arg->precision = ft_atoi(precision);
	arg->flags.precision = TRUE;
	next_i = ft_strlen(precision);
	if (precision != NULL)
	{
		free(precision);
		precision = NULL;
	}
	return (next_i + 1);
}

void	apply_precision(t_arg *arg)
{
	if (arg->type == T_STR)
		apply_str_pre(arg);
	else if (arg->type != T_STR && arg->type != T_WSTR
		&& arg->type != T_CHAR && arg->type != T_WCHAR)
		apply_nbr_pre(arg);
}

void	apply_str_pre(t_arg *arg)
{
	int	i;

	i = 0;
	if (arg->precision <= 0)
	{
		arg->conv_form->str[0] = '\0';
		arg->conv_form->len = 0;
		return ;
	}
	if ((int)arg->conv_form->len > arg->precision)
	{
		arg->conv_form->str[arg->precision] = '\0';
		arg->conv_form->len = arg->precision;
	}
}

void	apply_pre_zero(t_arg *arg)
{
	if (arg->flags.alt_form == TRUE && (arg->conv == 8 || arg->conv == 80))
	{
		arg->conv_form->str[1] = '\0';
		arg->conv_form->len = 1;
	}
	else if (arg->type == T_PTR)
	{
		arg->conv_form->str[2] = '\0';
		arg->conv_form->len = 2;
	}
	else
	{
		arg->conv_form->str[0] = '\0';
		arg->conv_form->len = 0;
	}
}
