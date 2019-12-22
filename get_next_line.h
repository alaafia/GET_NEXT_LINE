/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaafia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 19:21:52 by alaafia           #+#    #+#             */
/*   Updated: 2019/12/19 15:34:13 by alaafia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define LIMIT 256

size_t				ft_strlen(const char *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *src);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_substr(char const *s, unsigned int start, size_t len);
void				*ft_memset(void *str, int c, size_t n);
void				*ft_calloc(size_t nbr, size_t s);
int					put_line(int fd, int i, char **str);
int					get_line(int fd, char **line, char **str, int n);
int					get_next_line(int fd, char **line);
#endif
