/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaptist <mbaptist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:34:37 by mbaptist          #+#    #+#             */
/*   Updated: 2023/10/12 13:25:07 by mbaptist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
		*ptr++ = 0;
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

void	ft_putdigit(long long int n, int base, int *len)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n < 0)
	{
		n *= -1;
		*len += write(1, "-", 1);
	}
	if (n >= base)
		ft_putdigit((n / base), base, len);
	*len += write(1, &hex[n % base], 1);
}

int	ft_printf(const char *type, ...)
{
	int		len;
	va_list	pointer;

	len = 0;
	va_start(pointer, type);
	while (*type)
	{
		if ((*type == '%') && ((*(type + 1) == 's') || (*(type + 1) == 'd')
				|| (*(type + 1) == 'x')))
		{
			type++;
			if (*type == 's')
				ft_putstr_fd(va_arg(pointer, char *), 1);
			else if (*type == 'd')
				ft_putdigit((long long int)va_arg(pointer, int), 10, &len);
			else if (*type == 'x')
				ft_putdigit((long long int)va_arg(pointer, unsigned int), 16,
					&len);
		}
		else
			len += write(1, type, 1);
		type++;
	}
	return (va_end(pointer), len);
}
