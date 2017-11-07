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

int	new_flag_parsing(t_arg *arg, char *format, size_t i)
{
	int		next_i;
	int		f;
	char	*flags_tab;

	f = 0;
	next_i = -1;
	flags_tab = "#0-+ hljz.";
	while (flags_tab[f] != '\0')
	{
		if (format[i] == flags_tab[f])
		{
			next_i = new_check_flags_a(arg, format, i);
			if (next_i == -1)
				next_i = new_check_flags_b(arg, format, i);
		}
		f++;
	}
	if (ft_isdigit(format[i]) == 1 && format[i] != '0')
		next_i = set_width(arg, format + i);
	return (next_i);
}

int	new_check_flags_a(t_arg *arg, char *format, size_t i)
{
	int	next_i;

	next_i = -1;
	if (i + 1 < ft_strlen(format) && format[i] == 'h' && format[i + 1] == 'h')
		next_i = set_flag(arg, 'H');
	else if (i + 1 < ft_strlen(format)
		&& format[i] == 'l' && format[i + 1] == 'l')
		next_i = set_flag(arg, 'L');
	else if (format[i] == '-' || format[i] == '0')
		if (set_flag(arg, format[i]) != FALSE)
			next_i = get_width(format + i, arg);
	return (next_i);
}

int	new_check_flags_b(t_arg *arg, char *format, size_t i)
{
	int	next_i;

	next_i = -1;
	if (format[i] == ' ')
	{
		next_i = set_space_flag(arg, format, i);
		if (next_i == 0)
			next_i = ERROR;
	}
	else if (format[i] == '.')
	{
		next_i = set_precision(arg, format + i + 1);
		if (next_i == 0)
			next_i = ERROR;
	}
	else
	{
		next_i = set_flag(arg, format[i]);
		if (next_i == 0)
			next_i = ERROR;
	}
	return (next_i);
}
