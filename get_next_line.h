/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 16:43:55 by telain            #+#    #+#             */
/*   Updated: 2016/05/09 17:07:29 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/includes/libft.h"
# include <fcntl.h>
# define BUFF_SIZE 9999

typedef struct	s_gnl
{
	char		buf[BUFF_SIZE + 1];
	char		*str;
	int			start;
	int			end;
	int			fd;
}				t_gnl;

int				get_next_line(int const fd, char **line);

#endif
