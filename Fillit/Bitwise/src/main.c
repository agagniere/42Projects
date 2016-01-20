/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid <sid@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 10:43:36 by sid               #+#    #+#             */
/*   Updated: 2016/01/20 17:00:20 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int ac, char **av)
{
	t_tet		tetrimini[26];
	int			side[1];
	int			length[1];

	if (ac != 2
		|| fi_read(av[1], tetrimini, length)
		|| fi_solve(tetrimini, side, *length)
		|| fi_print(tetrimini, *side, *length))
		write(1, "error\n", 6);
	return (0);
}
