/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sq_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismherna <ismherna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:35:54 by ismherna          #+#    #+#             */
/*   Updated: 2024/10/23 16:36:01 by ismherna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

#ifndef O_RDONLY
# define O_RDONLY 0
#endif

#ifndef FD_MAX
# define FD_MAX 1024 
#endif

#define GNL_CALL 10000
#define THEN_DIFF 1 

/*
static void	ft_display_stats(void)
{
	pthread_attr_t	attr;
	size_t			stacksize;

	fprintf(stderr, ">> BUFFER_SIZE %d bytes", BUFFER_SIZE);
	fprintf(stderr, "  FD_MAX %d", FD_MAX);
	fprintf(stderr, "  GNL_CALL %d", GNL_CALL);
	pthread_attr_init(&attr);
	pthread_attr_getstacksize(&attr, &stacksize);
	fprintf(stderr, "  STACK SIZE %ld bytes\n", stacksize);
	pthread_attr_destroy(&attr);
}*/

int	main(int ac, char **av)
{
	char			*line;
	int				fd;
	int				i;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	if (!fd)
		return (1);
	i = 0;
	while (i++ < GNL_CALL)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (THEN_DIFF)
			printf("%s", line);
		else
			printf("line [%02d]: %s", i, line);
		free(line);
	}
	close(fd);
	return (0);
}
