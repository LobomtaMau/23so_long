/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaptist <mbaptist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:46:00 by mbaptist          #+#    #+#             */
/*   Updated: 2023/10/12 14:10:43 by mbaptist         ###   ########.fr       */
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

static int	ft_nblen(int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		len++;
	while (nb)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int				len;
	unsigned int	res;
	char			*str;

	len = ft_nblen(n);
	str = malloc(sizeof(*str) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = 0;
	if (n < 0)
	{
		res = -n;
		str[0] = '-';
	}
	else
		res = n;
	if (res == 0)
		str[0] = '0';
	while (len && res)
	{
		len--;
		str[len] = res % 10 + '0';
		res = res / 10;
	}
	return (str);
}
