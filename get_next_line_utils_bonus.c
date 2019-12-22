/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaafia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 18:15:07 by alaafia           #+#    #+#             */
/*   Updated: 2019/12/19 15:33:49 by alaafia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t				ft_strlen(const char *s)
{
	size_t			i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char				*ft_strchr(const char *s, int c)
{
	size_t				i;
	size_t				n;
	char				*str;

	str = (char *)s;
	i = 0;
	n = ft_strlen(str);
	while (i <= n)
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	return (NULL);
}

char				*ft_strdup(const char *src)
{
	char				*d;
	int					i;

	if (!(d = (char *)malloc(sizeof(char) * ft_strlen(src) + 1)))
		return (NULL);
	i = 0;
	while (src[i])
	{
		d[i] = src[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

void				*ft_memset(void *str, int c, size_t n)
{
	size_t						i;
	unsigned char				*dest;

	i = 0;
	dest = (unsigned char*)str;
	while (i < n)
	{
		dest[i] = (unsigned char)c;
		i++;
	}
	return ((void*)dest);
}

void				*ft_calloc(size_t nbr, size_t s)
{
	void				*p;

	p = malloc(nbr * s);
	if (!p)
		return (NULL);
	ft_memset(p, 0, (nbr * s));
	return (p);
}
