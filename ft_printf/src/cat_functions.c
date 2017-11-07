/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:50:50 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/16 22:50:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		cat_format(char *format, va_list ap)
{
	t_buff	*buff;
	t_arg	*arg;
	size_t	i;
	int		j;

	i = 0;
	if (!(arg = (t_arg *)malloc(1 * sizeof(t_arg)))
		|| !(buff = (t_buff *)malloc(1 * sizeof(t_buff))))
		return (ERROR);
	init_buffer(buff);
	init_arg(arg);
	while (i < ft_strlen(format))
	{
		if (format[i] == '%' && (i + 1) < ft_strlen(format))
		{
			if ((j = get_arg_str_form((format + i + 1), arg, ap)) == -1)
				return (-1);
			i = i + j;
			cat_buffer(buff, arg);
			reset_arg(arg);
		}
		else if (format[i] != '%')
			cat_str_buffer(buff, &format[i], 1);
		i++;
	}
	return (end(buff, arg));
}

void	free_ressources(t_arg *arg, t_buff *buff)
{
	if (arg != NULL)
	{
		if (arg->str_form != NULL)
			free(arg->str_form);
		if (arg->conv_form != NULL)
		{
			if (arg->conv_form->str != NULL)
				free(arg->conv_form->str);
			free(arg->conv_form);
		}
		free(arg);
	}
	if (buff != NULL)
	{
		if (buff->str != NULL)
			free(buff->str);
		free(buff);
	}
}

void	reset_arg(t_arg *arg)
{
	if (arg->str_form != NULL)
		ft_memset(arg->str_form, '\0', ft_strlen(arg->str_form));
	if (arg->conv_form->str != NULL)
		ft_memset(arg->conv_form->str, '\0', arg->conv_form->len);
	arg->conv_form->len = 0;
	arg->bonus = FALSE;
	arg->type = 0;
	arg->conv = 0;
	arg->argv.imax_arg = 0;
	arg->argv.uimax_arg = 0;
	arg->width = 0;
	arg->precision = 0;
	arg->wchar_form = FALSE;
	init_flags_arg(arg);
}

int		end(t_buff *buff, t_arg *arg)
{
	int	ret;

	write_buffer(buff);
	ret = buff->len;
	free_ressources(arg, buff);
	return (ret);
}
