/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 16:43:41 by telain            #+#    #+#             */
/*   Updated: 2016/05/16 17:16:40 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl		*new_struct(void)
{
	t_gnl	*new;

	new = ft_memalloc(sizeof(t_gnl));
	new->str = ft_strnew(BUFF_SIZE + 1);
	new->buf[BUFF_SIZE] = '\0';
	new->s = 0;
	new->end = 0;
	new->ret = 1;
	return (new);
}

int			find_len(char *str, int start)
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

int			find_bn(char *str, int start, int on)
{
	int index;

	index = 0;
	if (on == 1)
	{
		while (str[start] != '\0')
		{
			if (str[start] == '\n')
				return (start);
			start++;
		}
		return (-1);
	}
	else if (on == 0)
	{
		while (str[start++] != '\0')
			index++;
		return (index);
	}
	return (0);
}

int			sub_cpy(t_gnl *gnl, char **line)
{
	if (gnl->ret == 0)
	{
		*line = ft_strsub(gnl->str, gnl->s,
				find_bn(gnl->str, gnl->s, 0));
		gnl->end = 1;
		if (gnl->str[gnl->s - 1] == '\n'
				&& gnl->str[gnl->s] == '\0')
			return (0);
		return (1);
	}
	else
	{
		*line = ft_strsub(gnl->str, gnl->s,
				find_len(gnl->str, gnl->s));
		gnl->s = find_bn(gnl->str, gnl->s, 1) + 1;
		return (1);
	}
}

int			get_next_line(int const fd, char **line)
{
	static t_gnl	*gnl = NULL;

	if (fd < 0 || BUFF_SIZE < 1 || line == NULL)
		return (-1);
	!gnl ? gnl = new_struct() : gnl;
	gnl->ret = 1;
	if (gnl->end == 1)
	{
		*line = ft_strnew(0);
		gnl ? ft_memdel((void*)&gnl) : gnl;
		return (0);
	}
	while (find_bn(gnl->str, gnl->s, 1) == -1 && gnl->ret > 0)
	{
		if ((gnl->ret = read(fd, gnl->buf, BUFF_SIZE)) == -1)
			return (-1);
		gnl->buf[gnl->ret] = '\0';
		gnl->str = ft_strjoin(gnl->str, gnl->buf);
	}
	if (sub_cpy(gnl, line) == 0)
	{
		gnl ? ft_memdel((void*)&gnl) : gnl;
		return (0);
	}
	return (1);
}
