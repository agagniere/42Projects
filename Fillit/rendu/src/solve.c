/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 21:48:05 by angagnie          #+#    #+#             */
/*   Updated: 2016/01/19 01:38:35 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** | guess_what :   [| 1 ; 26 |]   ->   [| 2 ; 11 |]
** |                length        |->   side
** |
** | side being the smallest natural integer verifying :
** |    length * 4 <= side * side
*/
static int	guess_what(int const length)
{
	int         side;
	int const   cmp = length * 4;

	side = 2;
	while (side * side < cmp)
		side++;
	return (side);
}

static int	is_ok(t_i cur[4], int row, t_i mapbool[16])
{
	int i;

	i = 4;
	while (i-- > 0)
		if (cur[i] & mapbool[row + i])
			return (0);
	return (1);
}

static int	backtrack(t_i tet[26][4], int len, int side, t_map *map, int i)
{
	int		row;
	t_i		cur[4];
	int		a;

	if (i == len)
		return (1);
	row = 0;
	while (side - row > 3 || cur[side - row] == 0)
	{
		a = 4;
		while (a-- > 0)
			cur[a] = tet[i][a];
		while (!(cur[0] & (1 << side)) && !(cur[1] & (1 << side)) && !(cur[2] & (1 << side)))
		{
			if (is_ok(cur, row, map->bool))
			{
				fi_apply(map, cur, row, i);
				if (backtrack(tet, len, side, map, i + 1))
					return (1);
				fi_remove(map, cur, row);
			}
			((cur[0] <<= 1) && (cur[1] <<= 1)
				&& (cur[2] <<= 1) && (cur[3] <<= 1));
		}
		row++;
	}
	return (0);
}

void		init(t_i tetrimini[26][4], int len)
{
	int		side;
	t_map	map;

	side = 16;
	while (side-- > 0)
		map.bool[side] = 0;
	side = 256;
	while (side-- > 0)
		map.out[side] = '.';
	side = guess_what(len);
	while (!backtrack(tetrimini, len, side, &map, 0)) {
		side++;
	}
	print_solution(map.out, side);
}
