/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachfenn <aachfenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:18:22 by aachfenn          #+#    #+#             */
/*   Updated: 2022/11/01 12:35:52 by aachfenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//{reader()}is a function that will read from our file descriptor using
//the BUFFER_SIZE until we find the \n.(after copying thr buffer size we join 
//the strings)

char	*reader(char *container, int fd)
{
	char		*buf;
	int			p;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	p = 1;
	while (p != 0)
	{
		p = read(fd, buf, BUFFER_SIZE);
		if (p <= 0)
			break ;
		buf[p] = '\0';
		container = ft_strjoin(container, buf);
		if (ft_strchr(container, '\n'))
			break ;
	}
	free(buf);
	return (container);
}
// int main()
// {
// 	int fd;
// 	static char *container;
// 	fd = open("text.txt" ,O_RDONLY);
// 	printf("%s", reader(container, fd));
// }

char	*get_next_line(int fd)
{
	char		*final_res;
	static char	*container;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	container = reader(container, fd);
	if (!container)
		return (NULL);
	final_res = ft_get_line(container);
	container = cleaner(container);
	return (final_res);
}
