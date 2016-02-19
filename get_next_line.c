/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 17:08:42 by telain            #+#    #+#             */
/*   Updated: 2016/02/19 19:40:00 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*cpy_line(char *s, int start)
{
	int		i;
	char	*line;

	i = 0;
	line = malloc(1000);
	while (s[start] != '\n')
	{
		line[i++] = s[start++];
	}
	return (line);
}

int		find_backslash(char *s, int backslash, int lines)
{
	int		i;

	i = backslash;
	while (lines >= 0)
	{
		while (s[++i])
		{
			if (s[i] == '\n')
				return (i);
		}
		lines--;
	}
	return (-1);
}

s_value	*new_value(void)
{
	s_value	*new;

	new = malloc(sizeof(struct t_value));
	new->str = malloc(sizeof(char) * BUFF_SIZE + 1);
	new->backslash = -1;
	new->lines = 0;
	new->start = 0;
	return (new);
}

int		get_next_line(const int fd, char **line)
{
	static s_value	*value = NULL;
	int				ret;

	if (value == NULL)
		value = new_value();
	ret = read(fd, value->buff, BUFF_SIZE);
	value->buff[ret] = '\0';
	if (ret == 0)
		return (0);
	value->str = ft_strcat(value->str, value->buff);
	value->backslash = find_backslash(value->str, value->start, value->lines);
	if (value->backslash != -1)
	{
		value->lines++;
		*line = cpy_line(value->str, value->start);
		value->start = value->backslash + 1;
		return (1);
	}
	else
		return (get_next_line(fd, line));
	return (-1);
}
