/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid <sid@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 10:43:36 by sid               #+#    #+#             */
/*   Updated: 2016/01/18 21:41:29 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// --
#include <stdio.h>
// --

static int	fi_read(int fd)
{
	char		buffer[21];
	t_reader	all;
	int			l;

	all.index = 0;
	all.ret = 21;
	while (all.ret > 20)
	{
		all.ret = read(fd, buffer, 21);
		printf("Piece #%i\n", all.index);
		l = 4;
		while (l-- > 0)
			all.out[all.index][l] = 0;
		if (all.ret < 20 || fi_check(buffer, &all))
			return (1);
		all.index++;
	}
	return (0);
}

static int	fi_open(char *file_name)
{
	int		fd;
	int		ok;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (1);
	ok = fi_read(fd);
	close(fd);
	return (ok);
}

int			main(int ac, char **av)
{
	if (ac != 2 || fi_open(av[1]))
		write(1, "error\n", 6);
	return (0);
}
