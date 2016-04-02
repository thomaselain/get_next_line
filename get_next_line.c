/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <telain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 16:10:35 by telain            #+#    #+#             */
/*   Updated: 2016/04/02 21:38:47 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl	*new_gnl(void)
{
	t_gnl			*new;
	
	new = ft_memalloc(sizeof(struct s_gnl));
	new->str = ft_strnew(BUFF_SIZE * 2 + 1);
	new->start = 0;
	new->end = 0;
	return (new);
}

int		find_size(char *str, int start)
{
	int		i;

	i = 0;
	while (str[start] != '\n' && str[start] != '\0')
	{
		start++;
		i++;
	}
	return (i);
}

int		find_back(char *str, int start, int fct)
{
	int		i;

	i = start;
	if (fct == 1)
	{
		while (str[i])
		{
			if (str[i] == '\n')
				return (i);
			i++;
		}
		return (-1);
	}
	else
	{
		while (str[start++] != '\0')
			i++;
		return (i);
	}
	return (0);
}

int		sub_cpy(t_gnl *gnl, char **line, int ret)
{
	if (ret == 0)
	{
		*line = ft_strsub(gnl->str, gnl->start,	find_back(gnl->str, gnl->start, 0));
		gnl->end = 1;
		return (0);
	}
	else
	{
		*line = ft_strsub(gnl->str, gnl->start, find_size(gnl->str, gnl->start));
		gnl->start = find_back(gnl->str, gnl->start, 1) + 1;
		return (1);
	}
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*gnl = NULL;
	int				ret;

	if (fd < 0 || BUFF_SIZE < 1)
		return (-1);
	if (gnl == NULL)
		gnl = new_gnl();
	if (gnl->end == 1)
	{
		*line = NULL;
		free(gnl);
		return (0);
	}
	while (find_back(gnl->str, gnl->start, 1) == -1 && ret > 0)
	{

		ret = read(fd, gnl->buff, BUFF_SIZE);
		gnl->buff[ret] = '\0';
		gnl->str = ft_strjoin(gnl->str, gnl->buff);
	}
	sub_cpy(gnl, line, ret);
	return (1);
}
