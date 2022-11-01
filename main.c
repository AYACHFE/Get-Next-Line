/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachfenn <aachfenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 12:05:52 by aachfenn          #+#    #+#             */
/*   Updated: 2022/11/01 12:33:11 by aachfenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int	fd;

	fd = open("text.txt", O_RDONLY);
	printf("ligne 1 == %s", get_next_line(fd));
	printf("ligne 2 == %s", get_next_line(fd));
	printf("ligne 3 == %s", get_next_line(fd));
	printf("ligne 4 == %s", get_next_line(fd));
	printf("ligne 5 == %s", get_next_line(fd));
	printf("ligne 6 == %s", get_next_line(fd));
	printf("ligne 7 == %s", get_next_line(fd));
	printf("ligne 8 == %s", get_next_line(fd));
}
