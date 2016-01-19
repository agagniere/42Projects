/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 21:48:05 by angagnie          #+#    #+#             */
/*   Updated: 2016/01/19 06:32:14 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// ----
#include <stdio.h>
// -----

#define TEST(w)		(!(cur[w] & (1 << data.side)))
#define DECAL(w)	(cur[w] <<= 1)

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
	printf("Guessed : %i\n", side);
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

static int	backtrack(t_i tet[26][4], t_bt data, t_map *map, int i)
{
	int		row;
	t_i		cur[4];
	int		a;

//	printf("data.side = %i\n", data.side); /* <- */
	if (i == data.len)
		return (1);
	row = 0;
	while (data.side - row > 3 || cur[data.side - row] == 0)
	{
		a = 4;
		while (a-- > 0)
			cur[a] = tet[i][a];
		while (TEST(0) && TEST(1) && TEST(2))
		{
//			printf("(%i) Testing tetrimino #%i, @row %i\n", data.side, i, row); /* <- */
			if (is_ok(cur, row, map->bool))
			{
//				printf("Success\n"); /* <- */
				fi_apply(map, cur, row, i);
				if (backtrack(tet, data, map, i + 1))
					return (1);
				fi_remove(map, cur, row);
			}
//			else /* <- */
//				printf("Fail\n");/* <- */
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
	printf("Starting with side %i\n", side);
	while (!backtrack(tetrimini, (t_bt){len, side}, &map, 0)) {
		side++;
		printf("Restarting with side %i\n", side);
	}
	print_solution(map.out, side);
}
