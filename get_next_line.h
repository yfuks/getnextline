/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuks <yfuks@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 14:49:37 by yfuks             #+#    #+#             */
/*   Updated: 2016/12/14 16:06:59 by yfuks            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE	32

typedef struct	s_files
{
	int				fd;
	char			*line;
	char			ended;
	struct s_files	*next;
}				t_files;

int				get_next_line(const int fd, char **line);

#endif
