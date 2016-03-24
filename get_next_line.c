/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <telain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 16:10:35 by telain            #+#    #+#             */
/*   Updated: 2016/03/11 18:26:12 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_value		*new_value(void)
{
	t_value			*new;
	
	new = ft_memalloc(sizeof(struct s_value));
	new->str = ft_strnew(BUFF_SIZE * 2 + 1);
	new->start = 0;
	return (new);
}

int		find_size(char *str, int start)
{
	int		i;

	i = 0;
	while (str[start] != '\n' && str[start] != -1)
	{
		start++;
		i++;
	}
	return (i);
}

int		find_backslash(char *str, int start)
{
	int		i;

	i = start;
	while (str[i])
	{
		if (str[i] == '\n' || str[i] == -1)
			return (i);
		i++;
	}
	return (-1);
}

int		get_next_line(const int fd, char **line)
{
	static t_value	*value = NULL;
	int				ret;

	if (value == NULL)
		value = new_value();
	if (fd < 0)
		return (-1);
	while (find_backslash(value->str, value->start) == -1)
	{
		ret = read(fd, value->buff, BUFF_SIZE);
		value->buff[ret] = '\0';
		if (ret == 0)
			return (0);
		value->str = ft_strjoin(value->str, value->buff);
	}
	*line = ft_strsub(value->str, value->start, find_size(value->str, value->start));
	value->start = find_backslash(value->str, value->start) + 1;
	return (1);
}
