/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 09:37:48 by angagnie          #+#    #+#             */
/*   Updated: 2016/01/13 14:08:38 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** | guess_what :	[| 1 ; 26 |]   ->	[| 2 ; 11 |]
** |				length		  |->	side
** |
** | side being the smallest natural integer verifying :
** |	length * 4 <= side * side
*/
static t_i	guess_what(t_i const length)
{
	t_i			side;
	t_i const	cmp = length * 4;

	side = 2;
	while (side * side < cmp)
		side++;
	return (side);
}

static int	back_track(t_tetab tetrimini, t_i const length,
						t_i const side, t_i const i)
{
	t_tet *const	current = tetrimini[i];

	if (i == length)
		return (1);
	current->pos.coord.y = 0;
	while (current->pos.coord.y <= side - current->dim.height)
	{
		current->pos.coord.x = 0;
		while (current->pos.coord.x <= side - current->dim.width)
		{
			if (is_ok(tetrimini, i)
				&& back_track(tetrimini, length, side, i + 1))
				return (1);
			current->pos.coord.x += 1;
		}
		current->pos.coord.y += 1;
	}
	return (0);
}

void		solve(t_tetab tetrimini, t_i const length)
{
	t_i side;

	side = guess_what(length);
	while (!back_track(tetrimini, length, side, 0))
		side++;
	print_solution(tetrimini, length, side);
}
