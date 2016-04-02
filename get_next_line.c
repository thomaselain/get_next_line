/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <telain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 16:10:35 by telain            #+#    #+#             */
/*   Updated: 2016/04/02 20:58:27 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_value		*new_value(void)
{
	t_value			*new;
	
	new = ft_memalloc(sizeof(struct s_value));
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

int		find_backslash(char *str, int start, int fct)
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

int		sub_cpy(t_value *value, char **line, int ret)
{
	if (ret == 0)
	{
		*line = ft_strsub(value->str, value->start,	find_backslash(value->str, value->start, 0));
		value->end = 1;
		return (0);
	}
	else
	{
		*line = ft_strsub(value->str, value->start, find_size(value->str, value->start));
		value->start = find_backslash(value->str, value->start, 1) + 1;
		return (1);
	}
}

int		get_next_line(const int fd, char **line)
{
	static t_value	*value = NULL;
	int				ret;

	if (fd < 0 || BUFF_SIZE < 1)
		return (-1);
	if (value == NULL)
		value = new_value();
	if (value->end == 1)
	{
		*line = NULL;
		free(value);
		return (0);
	}
	while (find_backslash(value->str, value->start, 1) == -1 && ret > 0)
	{
		ret = read(fd, value->buff, BUFF_SIZE);
		value->buff[ret] = '\0';
		value->str = ft_strjoin(value->str, value->buff);
	}
	sub_cpy(value, line, ret);
	return (1);
}
