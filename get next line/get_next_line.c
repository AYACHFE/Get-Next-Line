/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachfenn <aachfenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:18:22 by aachfenn          #+#    #+#             */
/*   Updated: 2022/10/29 18:08:27 by aachfenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*final_res;
	static char	*container;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	container = reader(container, fd);
	final_res = get_ligne(container);
	container = cleaner(container);
	return (final_res);
}

// int main()
// {
// 	int fd;

// 	fd = open("text.txt" ,O_RDONLY);
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// }