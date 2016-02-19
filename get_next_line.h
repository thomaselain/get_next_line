/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 17:05:32 by telain            #+#    #+#             */
/*   Updated: 2016/02/19 19:40:00 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1
# include <stdio.h>
# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

typedef struct t_value
{
	int		backslash;
	int		lines;
	int		start;
	char	buff[BUFF_SIZE + 1];
	char	*str;
}				s_value;

int		get_next_line(const int fd, char **line);

#endif
