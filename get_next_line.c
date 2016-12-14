/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 15:36:37 by yfuks             #+#    #+#             */
/*   Updated: 2016/12/14 17:42:49 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"
#include "libft.h"

static	int	format_result(char **result, char **line, char **rest, int res)
{
	int		i;

	i = 0;
	if (res == 0)
	{
//		free(*result);
		return (0);
	}
	while (*result && result[0][i] && result[0][i] != '\n')
		i++;
	if (*result && result[0][i] == 0)
		*line = ft_strjoin_free(*line, *rest);
	else
	{
		result[0][i] = 0;
		*line = ft_strjoin(*rest, result[0]);
		*rest = ft_strdup(&(result[0][i + 1]));
	}
	free(*result);
	return (*line && *line[0] ? 1 : 0);
}

static	int	format_rest(char **rest, char **line)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = 0;
	while (*rest && rest[0][i] && rest[0][i] != '\n')
		i++;
	if (*rest && rest[0][i] == 0)
		*line = ft_strdup(*rest);
	else
	{
		rest[0][i] = 0;
		*line = ft_strdup(*rest);
		tmp = ft_strdup(&rest[0][i + 1]);
		free(*rest);
		*rest = tmp;
	}
	return (1);
}

static	int	get_line(const int fd, char **line, char **rest)
{
	char	*buff;
	int		res;
	char	*result;

	result = 0;
	if (*rest && ft_strchr(*rest, '\n'))
		return (format_rest(rest, line));
	if (!(buff = ft_memalloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	while ((res = read(fd, buff, BUFF_SIZE)))
	{
		buff[res] = '\0';
		result = ft_strjoin_free(result, buff);
		free(buff);
		if (ft_strchr(result, '\n') || res == 0)
			break;
		if (!(buff = ft_memalloc(sizeof(char) * (BUFF_SIZE + 1))))
			return (-1);
	}
	return (format_result(&result, line, rest, res));
}

int		get_next_line(const int fd, char **line)
{
	static	char	*rest;

	if (fd < 0)
		return (-1);
	return (get_line(fd, line, &rest));
}
