/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 21:48:05 by angagnie          #+#    #+#             */
/*   Updated: 2016/01/19 09:30:49 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define TEST(w)		(!(cur[w] & (1 << data.side)))
#define DECAL(w)	(cur[w] <<= 1)
#define ASSIGN(w)	(cur[w] = tet[i][w])

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
	return (!(cur[0] & mapbool[row])
		&& !(cur[1] & mapbool[row + 1])
		&& !(cur[2] & mapbool[row + 2])
		&& !(cur[3] & mapbool[row + 3]));
}

static int	backtrack(t_i tet[26][4], t_bt data, t_map *map, int i)
{
	int		row;
	t_i		cur[4];

	if (i == data.len)
		return (1);
	row = 0;
	while (data.side - row > 3 || cur[data.side - row] == 0)
	{
		(ASSIGN(0) && ASSIGN(1) && ASSIGN(2) && ASSIGN(3));
		while (TEST(0) && TEST(1) && TEST(2))
		{
			if (is_ok(cur, row, map->bool))
			{
				fi_apply(map, cur, row, i);
				if (backtrack(tet, data, map, i + 1))
					return (1);
				fi_remove(map, cur, row);
			}
			(DECAL(0) && DECAL(1) && DECAL(2) && DECAL(3));
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
	while (!backtrack(tetrimini, (t_bt){len, side}, &map, 0))
		side++;
	print_solution(map.out, side);
}
