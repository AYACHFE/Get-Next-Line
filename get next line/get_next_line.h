/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachfenn <aachfenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:25:49 by aachfenn          #+#    #+#             */
/*   Updated: 2022/11/01 12:36:49 by aachfenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// # include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

int		ft_strlen(const char *s);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*reader(char *container, int fd);
char	*ft_get_line(char *s);
char	*cleaner(char *s);
char	*ft_strchr(const char *s, int c);

#endif