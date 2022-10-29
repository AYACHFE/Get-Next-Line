/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachfenn <aachfenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:25:38 by aachfenn          #+#    #+#             */
/*   Updated: 2022/10/29 18:26:53 by aachfenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(const char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
//
//----------------------------------------------------------------------------\\
//

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*des;
	char	*sr;
	size_t	i;

	i = 0;
	des = dest;
	sr = (char *)src;
	if (!des && !src)
	{
		return (0);
	}
	while (n > i)
	{
		des[i] = sr[i];
		i++;
	}
	return (des);
}
//
//----------------------------------------------------------------------------\\
//

char    *ft_strjoin(char *s1, char *s2)
{
    char    *s;
    int        i;
    int        j;

    if (!s1 && !s2)
        return (NULL);
    i = ft_strlen(s1);
    j = ft_strlen(s2);
    s = (char *)malloc((i + j + 1) * sizeof(char));
    if (!s)
        return (NULL);
    ft_memcpy(s, s1, i);
    ft_memcpy(s + i, s2, j);
    s[i + j] = '\0';
    return (s);
}


char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*s1;

	s1 = (char *)s;
	i = 0;
	while (i < ft_strlen(s))
	{
		if (s1[i] == (char )c)
		{
			return (&s1[i]);
		}
		i++;
	}
	return (0);
}

//----------------------------------------------------------------------------\\

//{reader()}we will need a function that will read from our file descriptor using
//the BUFFER_SIZE until we find the \n.(after copying thr buffer size we join the strings)

char	*reader(char *container, int fd)
{
	char		*buf;
	int			p;

	p = 1;
	while (p > 0)
	{
		buf = malloc(BUFFER_SIZE + 1);
		p = read(fd, buf, BUFFER_SIZE);
		buf[p] = '\0';
		container = ft_strjoin(container, buf);
		if (!container)
			break ;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free (buf);
	return (container);
}
// int main()
// {
// 	int fd;
// 	static char *container;
// 	fd = open("text.txt" ,O_RDONLY);
// 	printf("%s", reader(container, fd));
// }

//----------------------------------------------------------------------------\\

// // {get_line}then we will need a function that copy from the reader() to this function .

char	*get_ligne(char *container)
{
	int		i;
	int		k;
	char	*p;

	i = 0;
	k = 0;
	// if (!container[i])
	// 	return (NULL);
	while (container[i] && container[i] != '\n')
	{
		i++;
	}
	p = malloc((i + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (container[i] && container[i] != '\n')
	{
		p[k] = container[i];
		k++;
		i++;
	}
	p[k] = '\0';
	return (p);
}

// int main()
// {
// 	int fd;
// 	static char *container;
// 	fd = open("text.txt" ,O_RDONLY);
// 	char *s = reader(container, fd);
// 	printf("%s", get_line(s));
// }
//----------------------------------------------------------------------------\\

//{cleaner()}we will need a function that will skip every thing that 
//we copied meaning that will start from(\n + 1).

char	*cleaner(char *container)
{
	int i;
	int k;
	char *p;

	i = 0;
	while (container[i] && container[i] != '\n')
	{
		i++;
	}
	p = malloc((ft_strlen(container) - i + 1));
	if (!p)
		// free(container);
		return (0);
	i++;
	k = 0;
	while (container[i])
	{
		p[k] = container[i];
		k++;
		i++;
	}
	p[k] = '\0';
	free(container);
	return (p);
}

// int main()
// {
// 	int fd;
// 	static char *container;
// 	fd = open("text.txt" ,O_RDONLY);
// 	container = reader(container, fd);
// 	printf("%s\n", cleaner(container));
// }
