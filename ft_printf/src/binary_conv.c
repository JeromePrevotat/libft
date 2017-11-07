/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:50:50 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/16 22:50:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	binary_conv(t_arg *arg)
{
	int		base;
	char	*tmp;

	tmp = NULL;
	base = arg->conv;
	tmp = cmp2(arg, base);
	arg->conv_form->len = ft_strlen(tmp);
	if (arg->conv_form->str != NULL)
	{
		free(arg->conv_form->str);
		arg->conv_form->str = NULL;
	}
	arg->conv_form->str = tmp;
}

char	*cmp2(t_arg *arg, int base)
{
	char	*tmp;
	int		len;

	len = get_len(arg);
	tmp = NULL;
	if (!(tmp = (char *)malloc((len) * sizeof(char))))
		return (NULL);
	ft_memset(tmp, '\0', len);
	tmp[len] = '\0';
	len--;
	while (len >= 0)
	{
		tmp[len] = ((arg->argv.i_arg) & (1 << len)) ? '1' : '0';
		len--;
	}
	return (strrev(tmp));
}

int		get_len(t_arg *arg)
{
	int	len;

	if (arg->type == T_SHORT)
	{
		len = sizeof(short) * 8;
		arg->argv.i_arg = arg->argv.imax_arg;
	}
	else if (arg->type == T_INT)
	{
		len = sizeof(int) * 8;
		arg->argv.i_arg = arg->argv.imax_arg;
	}
	else if (arg->type == T_LONG)
	{
		len = (sizeof(long) == 8) ? (sizeof(long) / 2) * 8 : sizeof(long) * 8;
		arg->argv.l_arg = arg->argv.imax_arg;
	}
	else if (arg->type == T_LLONG)
	{
		len = (sizeof(long long) * 8);
		arg->argv.ll_arg = arg->argv.imax_arg;
	}
	else
		len = (arg->type == T_IMAX) ? sizeof(intmax_t) * 8 : 0;
	return (len);
}

char	*strrev(char *str)
{
	int		i;
	int		len;
	char	tmp;

	if (!str)
		return (NULL);
	if (ft_strcmp(str, "") == 0)
		return (str);
	i = 0;
	len = ft_strlen(str) - 1;
	while (i <= len / 2)
	{
		tmp = str[i];
		str[i] = str[len - i];
		str[len - i] = tmp;
		i++;
	}
	return (str);
}
