/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachfenn <aachfenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:20:45 by aachfenn          #+#    #+#             */
/*   Updated: 2022/11/03 12:39:27 by aachfenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*reader(int fd, char *container)
{
	int		i;
	char	*p;

	p = malloc(BUFFER_SIZE + 1);
	if (!p)
		return (NULL);
	i = 1;
	while (i != 0)
	{
		i = read(fd, p, BUFFER_SIZE);
		if (i <= 0)
			break ;
		p[i] = '\0';
		container = ft_strjoin(container, p);
		if (ft_strchr(container, '\n'))
			break ;
	}
	free(p);
	return (container);
}

char	*get_next_line(int fd)
{
	static char	*container[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	container[fd] = reader(fd, container[fd]);
	if (!container[fd])
		return (NULL);
	line = get_ligne(container[fd]);
	container[fd] = cleaner(container[fd]);
	return (line);
}
