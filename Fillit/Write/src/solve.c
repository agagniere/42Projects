/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 09:37:48 by angagnie          #+#    #+#             */
/*   Updated: 2016/01/20 15:29:03 by angagnie         ###   ########.fr       */
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
					   t_i const side, char *map, t_i const i)
{
	int		x;
	int		y;

	if  (i == length)
		return (1);
	y = 0;
	while (y <= side - height)
	{
		x = 0;
		while (x <= side - width)
			if(is_ok(x, y, tetramini[i], map))
			{
				map[y * side + x] = 'A' + i;
				if (back_track(tetrimini, length, side, map, i + 1))
					return (1);
				map[y * side + x] = '.';
			}
		y++;
	}
	return (0);
}

int			go(tetrimini, length, side)
{
	char	map[side * side];

	if (back_track(tetrimini, length, side, map, 0))
	{
		print_solution(map, side);
		return (1);
	}
	return (0);
}

void		solve(t_tetab tetrimini, t_i const length)
{
	t_i side;

	side = guess_what(length);
	while (!go(tetrimini, length, side))
		side++;
}
