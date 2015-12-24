/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaitalla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 13:57:32 by yaitalla          #+#    #+#             */
/*   Updated: 2015/12/21 02:26:06 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

static int		begin(t_ai *all, char *file)
{
	int		fd;
	int		ans;

	fd = (file ? open(file, O_RDONLY) : 0);
	if (fd == -1)
		return (1);
	ans = initall(all, fd);
	if (ans == 0)
	{
		play(all);
		free(all->map);
		free(all->inverted);
	}
	if (file)
		close(fd);
	return (ans);
}

int				main(int ac, char **av)
{
	t_ai		all[1];

	*all = (t_ai){NULL, NULL, 0};
	if (ac > 3 || begin(all, av[1]))
		putcolor("ERROR", BOLD_RED, 2, 1);
	return (0);
}
