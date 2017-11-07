/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 22:50:50 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/16 22:50:50 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	ft_nb_len_imax(intmax_t n, int base)
{
	uintmax_t	nb;
	int			nb_len;

	nb = n;
	nb_len = 0;
	if (n < 0)
	{
		nb_len++;
		nb = -n;
	}
	while (nb / base > 0)
	{
		nb_len++;
		nb = nb / base;
	}
	return (nb_len);
}

char		*itoa_base_imax(intmax_t n, int base)
{
	char		*str;
	int			nb_len;
	uintmax_t	nb;
	char		hex;

	hex = (base == 160) ? 'A' : 'a';
	base = (base == 160) ? base / 10 : base;
	nb_len = ft_nb_len_imax(n, base);
	nb = (n < 0) ? -n : n;
	if (!(str = (char *)malloc((nb_len + 1) * sizeof(char))))
		return (NULL);
	ft_memset(str, '\0', nb_len + 1);
	str[nb_len + 1] = '\0';
	while (nb_len >= 0)
	{
		if (nb % base >= 10)
			str[nb_len] = hex + ((nb % base) - 10);
		else
			str[nb_len] = nb % base + '0';
		nb = nb / base;
		nb_len--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

static int	ft_nb_len_uimax(uintmax_t n, int base)
{
	uintmax_t	nb;
	int			nb_len;

	nb = n;
	nb_len = 0;
	while (nb / base > 0)
	{
		nb_len++;
		nb = nb / base;
	}
	return (nb_len);
}

char		*itoa_base_uimax(uintmax_t n, int base)
{
	char		*str;
	int			nb_len;
	uintmax_t	nb;
	char		hex;

	hex = (base == 160) ? 'A' : 'a';
	base = (base == 160) ? base / 10 : base;
	nb_len = ft_nb_len_uimax(n, base);
	nb = n;
	if (!(str = (char *)malloc((nb_len + 1) * sizeof(char))))
		return (NULL);
	ft_memset(str, '\0', nb_len + 1);
	str[nb_len + 1] = '\0';
	while (nb_len >= 0)
	{
		if (nb % base >= 10)
			str[nb_len] = hex + ((nb % base) - 10);
		else
			str[nb_len] = nb % base + '0';
		nb = nb / base;
		nb_len--;
	}
	return (str);
}
