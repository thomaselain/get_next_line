/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 17:05:32 by telain            #+#    #+#             */
/*   Updated: 2016/04/19 18:12:06 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 52
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
	int			fd;
}				t_gnl;

t_gnl			*new_gnl(int fd);
int				get_next_line(const int fd, char **line);
int				find_size(char *str, int start);
int				find_back(char *str, int start, int fct);
int				sub_cpy(t_gnl *gnl, char **line, int ret);

#endif
