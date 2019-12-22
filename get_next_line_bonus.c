/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaafia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 19:11:40 by alaafia           #+#    #+#             */
/*   Updated: 2019/12/22 20:59:11 by alaafia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	ft_len;
	char	*str;

	if (!s)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	ft_len = ft_strlen(s);
	while (i < len && start < ft_len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		k;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	if (!(res = (char *)malloc(sizeof(char) * (ft_strlen(s1) +
						ft_strlen(s2) + 1))))
		return (NULL);
	k = -1;
	while (s1[++k])
		res[k] = s1[k];
	i = 0;
	while (s2[i])
		res[k++] = s2[i++];
	res[k] = '\0';
	return (res);
}

int				put_line(int fd, int i, char **str)
{
	int				res;
	char			*temp;

	res = -1;
	temp = str[fd];
	if (str[fd][i] != '\0')
	{
		str[fd] = ft_strdup(str[fd] + i + 1);
		res = 1;
	}
	else
	{
		str[fd] = ft_strdup(str[fd] + i);
		res = 0;
	}
	free(temp);
	return (res);
}

int				get_line(int fd, char **line, char **str, int n)
{
	int					i;

	i = 0;
	if (str[fd] == NULL)
		return (0);
	while (str[fd][i] != '\0' && str[fd][i] != '\n')
		i++;
	if (str[fd][i] == '\n' || (str[fd][i] == '\0' && str[fd][0] != '\0'))
	{
		if (!(*line = ft_substr(str[fd], 0, i)))
			return (-1);
		return (put_line(fd, i, str));
	}
	if (!n && !*str[fd])
		str[fd] = NULL;
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char				*str[LIMIT];
	int						ret;
	char					*tmp;
	char					buffer[BUFFER_SIZE + 1];

	if (fd < 0 || fd > LIMIT || BUFFER_SIZE <= 0)
		return (-1);
	*str = ft_calloc(LIMIT, sizeof(char));
	while (!(ft_strchr(buffer, '\n')) &&
			(ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		tmp = str[fd];
		if (!(str[fd] = ft_strjoin(str[fd], buffer)))
			return (-1);
		if (tmp)
			free(tmp);
	}
	if (ret == -1)
		return (-1);
	return (get_line(fd, line, str, ret));
}
