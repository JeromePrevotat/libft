/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 14:59:53 by jprevota          #+#    #+#             */
/*   Updated: 2017/10/10 14:26:30 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

static int	check_nl(char *str)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char	*str_memcat(char *mem1, char *mem2, size_t size, int reset)
{
	char	*tmp;

	if (!(tmp = (char *)malloc(ft_strlen(mem1) + size + 1)))
		return (NULL);
	ft_memset(tmp, '\0', (size_t)(ft_strlen(mem1) + size + 1));
	ft_memcpy(tmp, mem1, ft_strlen(mem1));
	ft_memcpy(tmp + ft_strlen(mem1), mem2, size);
	tmp[ft_strlen(mem1) + size] = '\0';
	if (reset == 1)
		ft_memset(mem2, '\0', 256);
	if (mem1 != NULL)
		free(mem1);
	return (tmp);
}

static int	fill_buffer(int fd, char *buff)
{
	int		ret;

	if ((ret = read(fd, buff, BUFF_SIZE)) == -1)
		return (-1);
	buff[ret] = '\0';
	return (ret);
}

static int	gnl(char **line, const int fd, int ret)
{
	static char	buff_end[256];
	int			i;

	while (ret > 0)
	{
		if ((i = check_nl(buff_end)) >= 0)
		{
			*line = str_memcat(*line, buff_end, i, 0);
			ft_strcpy(buff_end, buff_end + i + 1);
			return (1);
		}
		if (ft_strlen(buff_end) + BUFF_SIZE + 1 > 256)
			*line = str_memcat(*line, buff_end, ft_strlen(buff_end), 1);
		if ((ret = fill_buffer(fd, buff_end + ft_strlen(buff_end))) == -1)
			return (-1);
		if (ret == 0 && ft_strlen(buff_end) > 0)
		{
			*line = str_memcat(*line, buff_end, ft_strlen(buff_end), 1);
			return (1);
		}
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	int		ret;

	ret = 1;
	if (!line || !(*line = (char *)malloc(BUFF_SIZE + 1 * sizeof(char)))
		|| fd < 0)
		return (-1);
	ft_memset(*line, '\0', (size_t)(BUFF_SIZE + 1));
	return (gnl(line, fd, ret));
}
