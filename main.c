/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telain <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 16:54:18 by telain            #+#    #+#             */
/*   Updated: 2016/02/19 19:18:26 by telain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(void)
{
	char	**pline;
	char	*line;
	int		fd;

	pline = &line;
	fd = open("fichier", O_RDONLY, S_IREAD);
	if (get_next_line(fd, pline) != -1)
		ft_putendl(line);
//	if (get_next_line(fd, pline) != -1)
//		ft_putendl(line);
//	if (get_next_line(fd, pline) != -1)
//		ft_putendl(line);
	return (0);
}
