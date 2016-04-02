/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 17:05:32 by telain            #+#    #+#             */
/*   Updated: 2016/04/02 21:25:22 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1
# include <stdlib.h>
# include "libft/includes/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

typedef struct	s_gnl
{
	char		buff[BUFF_SIZE + 1];
	char		*str;
	int			backslash;
	int			start;
	int			end;
}				t_gnl;

int				get_next_line(const int fd, char **line);

#endif
