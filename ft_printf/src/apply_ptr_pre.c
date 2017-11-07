/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_ptr_pre.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:50:50 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/16 22:50:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*apply_ptr_precision(t_arg *arg)
{
	char	*tmp;
	int		real_pre;

	tmp = NULL;
	real_pre = arg->precision - arg->conv_form->len + 2;
	if ((int)arg->conv_form->len < arg->precision)
		tmp = ptr_pre(arg, real_pre);
	if (tmp == NULL)
		return (ft_strdup(arg->conv_form->str));
	return (tmp);
}

char	*ptr_pre(t_arg *arg, int real_pre)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 2;
	if (!(tmp = (char *)malloc(arg->precision + 1 * sizeof(char))))
		return (NULL);
	ft_memset(tmp, '\0', arg->precision + 1);
	while (i < 2 && i < arg->precision)
	{
		tmp[i] = arg->conv_form->str[i];
		i++;
	}
	while (i < real_pre + 2)
	{
		tmp[i] = '0';
		i++;
	}
	ft_memcpy(tmp + i, arg->conv_form->str + 2, arg->conv_form->len - 2);
	tmp[i + arg->conv_form->len - 2] = '\0';
	return (tmp);
}
