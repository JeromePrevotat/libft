/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undefined_behaviour.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:50:50 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/16 22:50:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*get_undefined_behaviour(t_arg *arg)
{
	int		i;

	i = 0;
	if (arg->str_form != NULL)
	{
		while (ub_is_flag(arg->str_form[i], arg)
			&& i < ft_strlen(arg->str_form))
			i++;
		if (i - 1 >= 0 && ((ub_is_flag(arg->str_form[i - 1], arg)
			|| arg->str_form[i - 1] == 'h' || arg->str_form[i - 1] == 'l')))
		{
			arg->conv_form->len = ft_strlen(arg->str_form + i);
			return (ft_strdup(arg->str_form + i));
		}
		if (i - 1 >= 0)
		{
			arg->conv_form->len = ft_strlen(arg->str_form + i - 1);
			return (ft_strdup(arg->str_form + i - 1));
		}
		arg->conv_form->len = ft_strlen(arg->str_form + i);
		return (ft_strdup(arg->str_form + i));
	}
	return (NULL);
}

int		ub_is_flag(char c, t_arg *arg)
{
	char	*flags_tab;
	size_t	i;

	i = 0;
	flags_tab = "#0-+ hljz.\0";
	while (flags_tab[i] != '\0')
	{
		if (c == flags_tab[i] || ft_isdigit(c))
		{
			if (c == '.')
				set_precision(arg, arg->str_form + i + 1);
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}
