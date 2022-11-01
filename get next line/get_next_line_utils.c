/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachfenn <aachfenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:25:38 by aachfenn          #+#    #+#             */
/*   Updated: 2022/11/01 12:37:41 by aachfenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

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

char	*ft_strjoin(char *s1, char*s2)
{
	int		i;
	int		j;
	char	*p;
	int		len;
	int		k;

	k = 0;
	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	p = malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	while (s1 && s1[i])
		p[k++] = s1[i++];
	while (s2 && s2[j])
		p[k++] = s2[j++];
	p[k] = '\0';
	free(s1);
	return (p);
}
//
//----------------------------------------------------------------------------\\
//

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*s1;
	char	c1;

	s1 = (char *)s;
	c1 = (char )c;
	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		if (s1[i] == c1)
		{
			return (&s1[i]);
		}
		i++;
	}
	return (0);
}

//----------------------------------------------------------------------------\\

// // {get_line()}is  a function that copy from the reader() to this function .

char	*ft_get_line(char *container)
{
	int		i;
	char	*p;

	i = 0;
	if (!container[i])
		return (NULL);
	while (container[i] && container[i] != '\n')
	{
		i++;
	}
	p = malloc((i + 2));
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

// int main()
// {
// 	int fd;
// 	static char *container;
// 	fd = open("text.txt" ,O_RDONLY);
// 	container = reader(container, fd);
// 	printf("%s.", get_ligne(container));
// }

//----------------------------------------------------------------------------\\

//{cleaner()}Is a function that will skip every thing that 
//we copied meaning that will start from(\n + 1).

char	*cleaner(char *container)
{
	int		i;
	int		k;
	char	*p;
	int		len;

	i = 0;
	len = ft_strlen(container);
	while (container[i] && container[i] != '\n')
		i++;
	if (!container[i] || (container[i] == '\n' && container[i + 1] == '\0'))
	{
		free (container);
		return (NULL);
	}
	p = malloc(len - i);
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

// int main()
// {
// 	int fd;
// 	static char *container;
// 	fd = open("text.txt" ,O_RDONLY);
// 	container = reader(container, fd);
// 	printf("%s\n", cleaner(container));
// }
