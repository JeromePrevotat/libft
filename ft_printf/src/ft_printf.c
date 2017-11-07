/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:50:50 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/16 22:50:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		ret;
	va_list	ap;
	char	*f;
	size_t	i;

	MB_CUR_MAX = 4;
	i = 0;
	f = ft_strdup(format);
	va_start(ap, format);
	ret = cat_format(f, ap);
	va_end(ap);
	free(f);
	return (ret);
}

int	get_arg_str_form(char *format, t_arg *arg, va_list ap)
{
	size_t	i;
	int		next_i;

	i = 0;
	next_i = 1;
	while (i < ft_strlen(format) - 1 && next_i > 0)
	{
		next_i = new_flag_parsing(arg, format, i);
		if (next_i > 0)
			i = i + next_i;
	}
	if (i < ft_strlen(format) && is_conversion(format[i]) == TRUE)
	{
		arg->str_form = str_memcat(arg->str_form, format, i + 1, 1);
		if (fill_arg(arg, ap) == -1)
			return (-1);
		return (i + 1);
	}
	else if (i < ft_strlen(format) && is_conversion(format[i]) == FALSE)
		arg->str_form = str_memcat(arg->str_form, format, i + 1, 1);
	else
		arg->str_form = str_memcat(arg->str_form, format, ft_strlen(format), 1);
	arg->conv_form->str = get_undefined_behaviour(arg);
	apply_flags(arg);
	return (i + 1);
}
