/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:08:54 by jprevota          #+#    #+#             */
/*   Updated: 2017/10/29 16:54:27 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static int	ft_word_count(char const *s, char c)
{
	size_t	i;
	int		word;

	word = 0;
	i = 0;
	while (i < ft_strlen(s))
	{
		while (s[i] == c && i < ft_strlen(s))
			i++;
		if (s[i] != c && i < ft_strlen(s))
			word++;
		while (s[i] != c && i < ft_strlen(s))
			i++;
		i++;
	}
	return (word);
}

static char	*ft_word_start(char *s, char c, int wl)
{
	char	*str;
	size_t	i;

	i = 0;
	while (s[i + wl] == c && i < ft_strlen(s))
		i++;
	str = ft_strdup(s + i + wl);
	if (s != NULL)
		free(s);
	return (str);
}

static int	ft_word_len(char c, char *word)
{
	int i;

	i = 0;
	while (word[i] != c && word[i] != '\0')
		i++;
	return (i);
}

static char	*ft_split(char *word, int len)
{
	char *str;

	str = (char *)malloc((len) * sizeof(char));
	str = ft_strncpy(str, word, len);
	str[len] = '\0';
	return (str);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	char	*str;
	int		wc;
	int		wl;
	int		i;

	i = 0;
	wl = 0;
	if (!s)
		return (NULL);
	str = ft_strdup(s);
	wc = ft_word_count(str, c);
	if (!(tab = (char **)malloc((wc + 1) * sizeof(char *))))
		return (NULL);
	while (i < wc)
	{
		str = ft_word_start(str, c, wl);
		wl = ft_word_len(c, str);
		if (!(tab[i] = ft_split(str, wl)))
			return (NULL);
		i++;
	}
	tab[i] = NULL;
	free(str);
	return (tab);
}
