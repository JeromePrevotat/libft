/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_nbr_pre.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:50:50 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/16 22:50:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	apply_nbr_pre(t_arg *arg)
{
	char	*tmp;

	tmp = NULL;
	if (arg->precision == 0 && argv_sign(arg) == 0)
	{
		apply_pre_zero(arg);
		return ;
	}
	if (argv_sign(arg) < 0 && arg->type != T_PTR)
		tmp = apply_negative(arg);
	else if (argv_sign(arg) >= 0 && arg->type != T_PTR)
		tmp = apply_positive(arg);
	else if (arg->type == T_PTR)
		tmp = apply_ptr_precision(arg);
	if (arg->conv_form->str != NULL)
	{
		free(arg->conv_form->str);
		arg->conv_form->str = NULL;
	}
	arg->conv_form->len = ft_strlen(tmp);
	arg->conv_form->str = tmp;
}

char	*apply_negative(t_arg *arg)
{
	size_t	i;
	size_t	real_pre;
	char	*tmp;

	tmp = NULL;
	real_pre = arg->precision - arg->conv_form->len + 1;
	if ((int)arg->conv_form->len - 1 < arg->precision)
	{
		i = 1;
		if (!(tmp = (char *)malloc((real_pre + arg->conv_form->len + 1)
			* sizeof(char))))
			return (NULL);
		ft_memset(tmp, '\0', (real_pre + arg->conv_form->len + 1));
		tmp[0] = '-';
		while (i < real_pre + 1)
		{
			tmp[i] = '0';
			i++;
		}
		ft_memcpy(tmp + i, arg->conv_form->str + 1, arg->conv_form->len - 1);
		tmp[real_pre + arg->conv_form->len + 1] = '\0';
	}
	if (tmp == NULL)
		return (ft_strdup(arg->conv_form->str));
	return (tmp);
}

char	*apply_positive(t_arg *arg)
{
	size_t	i;
	size_t	real_pre;
	char	*tmp;

	tmp = NULL;
	real_pre = arg->precision;
	if (arg->conv_form->len < real_pre)
	{
		i = 0;
		if (!(tmp = (char *)malloc((real_pre - arg->conv_form->len + 1)
			* sizeof(char))))
			return (NULL);
		ft_memset(tmp, '\0', (real_pre - arg->conv_form->len + 1));
		while (i < real_pre - arg->conv_form->len)
		{
			tmp[i] = '0';
			i++;
		}
		tmp[i] = '\0';
		tmp = str_memcat(tmp, arg->conv_form->str, arg->conv_form->len, 1);
	}
	if (tmp == NULL)
		return (ft_strdup(arg->conv_form->str));
	return (tmp);
}
