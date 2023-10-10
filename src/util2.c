/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaptist <mbaptist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:34:44 by mbaptist          #+#    #+#             */
/*   Updated: 2023/10/06 12:34:45 by mbaptist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total_size;

	total_size = count * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	else
		ft_bzero(ptr, count * size);
	return (ptr);
}

static int	ft_newline(char *s)
{
	int	i;
	int	j;
	int	new_line;

	i = 0;
	j = 0;
	new_line = 0;
	while (s[i] && s[i] != '\n')
		s[i++] = '\0';
	if (s[i] == '\n')
	{
		new_line = 1;
		s[i++] = '\0';
		while (s[i])
		{
			s[j++] = s[i];
			s[i++] = '\0';
		}
	}
	return (new_line);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	char	*news;
	char	*res;
	int		i;

	if (s2[0] == '\0')
		return (0);
	i = 0;
	news = (char *)malloc(sizeof(char) * ft_strlen(s1) + BUFFER_SIZE + 1);
	res = news;
	if (!news)
	{
		free(news);
		return (NULL);
	}
	while (s1 && s1[i] != 0)
		*news++ = s1[i++];
	if (s1)
		free(s1);
	while (s2 && *s2 != 0 && *s2 != '\n')
		*news++ = *s2++;
	if (*s2 == '\n')
		*news++ = '\n';
	*news = 0;
	return (res);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	content[BUFFER_SIZE];
	int			c;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > FOPEN_MAX)
		return (NULL);
	str = ft_strjoin(NULL, content);
	if (ft_newline(content) > 0)
		return (str);
	c = read(fd, content, BUFFER_SIZE);
	if (c < 0)
	{
		free(str);
		return (NULL);
	}
	while (c > 0 || *content != 0)
	{
		str = ft_strjoin(str, content);
		if (ft_newline(content) > 0)
			break ;
		c = read(fd, content, BUFFER_SIZE);
	}
	return (str);
}

char	*ft_append_strs(char **s1, const char *s2)
{
	char	*str;

	if (!*s1 || !s2)
		return (NULL);
	str = (char *)ft_calloc((ft_strlen(*s1) + ft_strlen(s2)) + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, *s1, ft_strlen(*s1) + 1);
	ft_strlcat(str, s2, ft_strlen(*s1) + ft_strlen(s2) + 1);
	free(*s1);
	return (str);
}
