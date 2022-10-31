/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachfenn <aachfenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 12:05:52 by aachfenn          #+#    #+#             */
/*   Updated: 2022/10/31 14:48:40 by aachfenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main()
{
	int fd;

	fd = open("text.txt" ,O_RDONLY);
	printf("ligne 1 == %s.\n", get_next_line(fd));
	printf("ligne 2 == %s.\n", get_next_line(fd));
	printf("ligne 3 == %s.\n", get_next_line(fd));
	printf("ligne 4 == %s.\n", get_next_line(fd));
	printf("ligne 5 == %s.\n", get_next_line(fd));
	printf("ligne 6 == %s.\n", get_next_line(fd));
	printf("ligne 7 == %s.\n", get_next_line(fd));
	printf("ligne 8 == %s.\n", get_next_line(fd));

}