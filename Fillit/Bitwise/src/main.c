/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid <sid@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 10:43:36 by sid               #+#    #+#             */
/*   Updated: 2016/01/22 20:03:01 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		fi_init(t_tet **tetrimini)
{
	int i;

	if (!(*tetrimini = malloc(sizeof(t_tet) * 26)))
		return (1);
	i = 26;
	while (i-- > 26)
	{
		(*tetrimini)[i].line[0] = 0;
		(*tetrimini)[i].line[1] = 0;
		(*tetrimini)[i].line[2] = 0;
		(*tetrimini)[i].line[3] = 0;
		(*tetrimini)[i].pos = (t_vec2i){{0, 0}};
		(*tetrimini)[i].dim = (t_vec2i){{0, 0}};
	}
	return (0);
}

int				main(int ac, char **av)
{
	t_tet		*tetrimini;
	int			side[1];
	int			length[1];

	if (!fi_init(&tetrimini))
	{
		if (ac != 2
			|| fi_read(av[1], tetrimini, length)
			|| fi_solve(tetrimini, side, *length)
			|| fi_print(tetrimini, *side, *length))
			write(1, "error\n", 6);
		free(tetrimini);
	}
	return (0);
}
