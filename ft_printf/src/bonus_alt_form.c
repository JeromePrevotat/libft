/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_alt_form.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:50:50 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/16 22:50:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	bytes_form(t_arg *arg)
{
	char	*tmp;

	tmp = apply_bytes_form(arg);
	if (arg->conv_form->str != NULL)
		free(arg->conv_form->str);
	arg->conv_form->len = ft_strlen(tmp);
	arg->conv_form->str = tmp;
}

char	*apply_bytes_form(t_arg *arg)
{
	char	*tmp;
	int		i;
	int		j;
	int		len;

	tmp = NULL;
	i = 0;
	j = 0;
	len = (ft_strlen(arg->conv_form->str) / 8) + ft_strlen(arg->conv_form->str);
	if (!(tmp = (char *)malloc(len + 1 * sizeof(char))))
		return (NULL);
	ft_memset(tmp, '\0', len + 1);
	while (i < len)
	{
		ft_memcpy(tmp + i + j, arg->conv_form->str + i, 4);
		i = i + 4;
		tmp[i + j] = ' ';
		j++;
		ft_memcpy(tmp + i + j, arg->conv_form->str + i, 4);
		i = i + 4;
		tmp[i + j] = (i + j < len) ? '\t' : '\0';
		j++;
	}
	return (tmp);
}
