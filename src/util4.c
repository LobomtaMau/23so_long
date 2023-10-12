/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: struf <struf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:46:00 by mbaptist          #+#    #+#             */
/*   Updated: 2023/10/12 11:32:18 by struf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != '\0')
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static int	ft_word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		n_words;
	int		i;

	if (!s)
		return (NULL);
	n_words = ft_count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (n_words + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < n_words)
	{
		while (*s && *s == c)
			s++;
		res[i] = ft_substr(s, 0, ft_word_len(s, c));
		s += ft_word_len(s, c);
		i++;
	}
	res[i] = NULL;
	return (res);
}

void	ft_free_strarr(char **strarr)
{
	int	i;

	if (strarr)
	{
		i = 0;
		while (strarr[i])
		{
			free(strarr[i]);
			i++;
		}
		free(strarr);
	}
}

static int	ft_nblen(int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
	{
		return (1);
	}
	if (nb < 0)
	{
		len++;
	}
	while (nb)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}
