/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:50:50 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/16 22:50:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*str_memcat(char *mem1, char *mem2, size_t size, int del)
{
	char	*tmp;

	if (mem1 == NULL)
	{
		if (!(mem1 = (char *)malloc(1 * sizeof(char))))
			return (NULL);
		ft_memset(mem1, '\0', 1);
	}
	if (mem2 == NULL)
	{
		if (!(mem2 = (char *)malloc(1 * sizeof(char))))
			return (NULL);
		ft_memset(mem2, '\0', 1);
	}
	if (!(tmp = (char *)malloc((ft_strlen(mem1) + size + 1) * sizeof(char))))
		return (NULL);
	ft_memset(tmp, '\0', (size_t)(ft_strlen(mem1) + size + 1));
	ft_memcpy(tmp, mem1, ft_strlen(mem1));
	ft_memcpy(tmp + ft_strlen(mem1), mem2, size);
	tmp[ft_strlen(mem1) + size] = '\0';
	sfree(mem1, mem2, del);
	return (tmp);
}

void	sfree(char *mem1, char *mem2, int del)
{
	if (del == 1 && mem1 != NULL)
	{
		free(mem1);
		mem1 = NULL;
	}
	if (del == 2 && mem2 != NULL)
	{
		free(mem2);
		mem2 = NULL;
	}
	if (del == 3 && mem1 != NULL && mem2 != NULL)
	{
		free(mem1);
		free(mem2);
		mem1 = NULL;
		mem2 = NULL;
	}
}

int		get_width(char *str, t_arg *arg)
{
	size_t	j;
	size_t	i;
	char	*tmp;

	j = 1;
	while (j < ft_strlen(str) && ft_isdigit(str[j]))
		j++;
	if (!(tmp = (char *)malloc((j + 1) * sizeof(char))))
		return (ERROR);
	ft_memset(tmp, '\0', j + 1);
	i = 0;
	while (i < j)
	{
		tmp[i] = str[i + 1];
		i++;
	}
	tmp[i] = '\0';
	if (ft_atoi(tmp) > arg->width)
		arg->width = ft_atoi(tmp);
	if (tmp != NULL)
	{
		free(tmp);
		tmp = NULL;
	}
	return (j);
}

int		argv_sign(t_arg *arg)
{
	if (arg->argv.imax_arg > 0)
		return (1);
	else if (arg->argv.imax_arg < 0)
		return (-1);
	return (0);
}
