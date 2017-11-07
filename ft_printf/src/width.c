/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:50:50 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/16 22:50:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		set_width(t_arg *arg, char *str_form)
{
	size_t	i;
	char	*width;
	int		next_i;

	i = 0;
	next_i = 0;
	if (!(width = (char *)malloc(ft_strlen(str_form) * sizeof(char))))
		return (ERROR);
	ft_memset(width, '\0', ft_strlen(str_form));
	while (i < ft_strlen(str_form) && ft_isdigit(str_form[i]))
	{
		width[i] = str_form[i];
		i++;
	}
	width[i] = '\0';
	arg->width = ft_atoi(width);
	arg->flags.width = TRUE;
	if (ft_strlen(width) == 0)
		next_i = 1;
	else
		next_i = ft_strlen(width);
	if (width != NULL)
		free(width);
	return (next_i);
}

void	apply_width(t_arg *arg)
{
	char	*tmp;
	int		real_width;
	int		i;

	i = 0;
	real_width = 0;
	tmp = NULL;
	real_width = get_str_with(arg);
	if (real_width >= 0)
	{
		if (!(tmp = (char *)malloc((arg->width + 1) * sizeof(char))))
			return ;
		ft_memset(tmp, '\0', (arg->width + 1));
		while (i < real_width)
		{
			tmp[i] = ' ';
			i++;
		}
		tmp[i] = '\0';
		tmp = str_memcat(tmp, arg->conv_form->str, arg->conv_form->len, 1);
		if (arg->conv_form->str != NULL)
			free(arg->conv_form->str);
		arg->conv_form->len = arg->conv_form->len + real_width;
		arg->conv_form->str = tmp;
	}
}

int		get_str_with(t_arg *arg)
{
	int	real_width;

	real_width = 0;
	if (arg->type == T_CHAR && arg->argv.c_arg == 0)
		real_width = arg->width - 1;
	else
		real_width = arg->width - arg->conv_form->len;
	return (real_width);
}
