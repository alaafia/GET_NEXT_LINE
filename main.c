/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaafia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 19:04:38 by alaafia           #+#    #+#             */
/*   Updated: 2020/01/22 16:44:04 by alaafia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int				main()
{
	int			fd;
	char		*line;
	int i;


	i = 1;
	fd = open("bigg",O_RDONLY);
	while (i > 0)
	{
		i = get_next_line(fd, &line);
		printf("%d----------%s\n",i,line);
		free(line);
	}
	i = get_next_line(fd,&line);
	printf("%d----------%s\n",i,line);

i = get_next_line(0, &line);
		printf("%d----------%s\n",i,line);
		free(line);
i = get_next_line(0, &line);
		printf("%d----------%s\n",i,line);
		free(line);

	int fd2 = open("txt", O_RDONLY);
		while (i > 0)
	{
		i = get_next_line(fd2, &line);
		printf("%d----------%s\n",i,line);
		free(line);
	}
	i = get_next_line(fd2,&line);
	printf("%d----------%s\n",i,line);
}
