/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachfenn <aachfenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:20:45 by aachfenn          #+#    #+#             */
/*   Updated: 2022/11/03 12:39:19 by aachfenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//{reader()}is a function that will read from our file descriptor using
//the BUFFER_SIZE until we find the \n.(after copying thr buffer size we join 
//the strings)

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

// int main()
// {
// 	int fd;
// 	static char *container;
// 	fd = open("text.txt", O_RDONLY);
// 	printf("%s",reader(fd, container));
// }

char	*get_next_line(int fd)
{
	static char	*container;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	container = reader(fd, container);
	if (!container)
		return (NULL);
	line = get_ligne(container);
	container = cleaner(container);
	return (line);
}
