/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachfenn <aachfenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:20:45 by aachfenn          #+#    #+#             */
/*   Updated: 2022/11/04 16:58:37 by aachfenn         ###   ########.fr       */
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
		if (checker(container))
			break ;
	}
	free(p);
	return (container);
}

char	*get_ligne(char *container)
{
	int		i;
	char	*p;

	i = 0;
	if (!container)
		return (NULL);
	while (container[i] && container[i] != '\n')
		i++;
	p = malloc(i + 2);
	if (!p)
		return (NULL);
	i = 0;
	while (container[i] && container[i] != '\n')
	{
		p[i] = container[i];
		i++;
	}
	if (container[i] == '\n')
		p[i++] = '\n';
	p[i] = '\0';
	return (p);
}

char	*cleaner(char *container)
{
	int		i;
	int		k;
	char	*p;

	i = 0;
	while (container[i] && container[i] != '\n')
		i++;
	if (!container[i] || (container[i] == '\n' && container[i + 1] == '\0'))
	{
		free(container);
		return (NULL);
	}
	p = malloc(ft_strlen(container) - i);
	if (!p)
		return (NULL);
	i++;
	k = 0;
	while (container[i])
		p[k++] = container[i++];
	p[k] = '\0';
	free(container);
	return (p);
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
