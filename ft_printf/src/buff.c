/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:50:50 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/16 22:50:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	init_buffer(t_buff *buff)
{
	buff->str = NULL;
	buff->len = 0;
}

void	write_buffer(t_buff *buff)
{
	write(1, buff->str, buff->len);
}

void	cat_buffer(t_buff *buff, t_arg *arg)
{
	char	*new_buff;

	if (!(new_buff = (char *)malloc((arg->conv_form->len + buff->len + 1)
		* sizeof(char))))
		return ;
	ft_memset(new_buff, '\0', arg->conv_form->len + buff->len + 1);
	ft_memcpy(new_buff, buff->str, buff->len);
	ft_memcpy(new_buff + buff->len, arg->conv_form->str, arg->conv_form->len);
	new_buff[buff->len + arg->conv_form->len] = '\0';
	buff->len = buff->len + arg->conv_form->len;
	if (buff->str != NULL)
	{
		free(buff->str);
		buff->str = NULL;
	}
	buff->str = new_buff;
}

void	cat_str_buffer(t_buff *buff, char *src, size_t size)
{
	char	*new_buff;

	if (!(new_buff = (char *)malloc((size + buff->len + 1) * sizeof(char))))
		return ;
	ft_memset(new_buff, '\0', size + buff->len + 1);
	ft_memcpy(new_buff, buff->str, buff->len);
	ft_memcpy(new_buff + buff->len, src, size);
	new_buff[buff->len + size] = '\0';
	if (buff->str != NULL)
	{
		free(buff->str);
		buff->str = NULL;
	}
	buff->str = new_buff;
	buff->len = buff->len + size;
}
