/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 14:56:41 by yfuks             #+#    #+#             */
/*   Updated: 2016/12/14 18:04:10 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int		main(int ac, char *av[])
{
	char	*line;
	int		fd;

	if (ac < 2)
	{
		puts("usage: a.out file");
		return (-1);
	}
	line = 0;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) != 0)
	{
		puts(line);
//		puts("--------------------------");
		free(line);
	}
	close(fd);
	sleep(10);
	return (0);
}
