/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 21:48:05 by angagnie          #+#    #+#             */
/*   Updated: 2016/01/22 14:01:18 by sid              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
// ---
#include <stdio.h>
// ===

/*
** | guess_what :   [| 1 ; 26 |]   ->   [| 2 ; 11 |]
** |                length        |->   side
** |
** | side being the smallest natural integer verifying :
** |    length * 4 <= side * side
*/
static int		guess_what(int const length)
{
	int         side;
	int const   cmp = length * 4;

	side = 2;
	while (side * side < cmp)
		side++;
	return (side);
}

static int		is_ok(t_tet const *const cur, t_map const *const map)
{
	return (!(cur->line[0] & map->line[cur->pos.c.y])
		&& !(cur->line[1] & map->line[cur->pos.c.y + 1])
		&& !(cur->line[2] & map->line[cur->pos.c.y + 2])
		&& !(cur->line[3] & map->line[cur->pos.c.y + 3]));
}

static t_map	apply(t_map map, t_tet const *const cur)
{
	map.line[cur->pos.c.y] |= cur->line[0];
	map.line[cur->pos.c.y + 1] |= cur->line[1];
	map.line[cur->pos.c.y + 2] |= cur->line[2];
	map.line[cur->pos.c.y + 3] |= cur->line[3];
	return (map);
}

static int		back_track(t_tet tetrimini[26],
	int const length, t_map map, int i)
{
	t_tet cur = tetrimini[i];

	if (i == length)
		return (1);
	cur.pos.c.y = 0;
	printf("Piece #%i (%i, %i)\n", i, cur.dim.c.x, cur.dim.c.y);fflush(stdout);
	while (cur.pos.c.y <= map.side - cur.dim.c.y)
	{
		cur.pos.c.x = 0;
		while (cur.pos.c.x <= map.side - cur.dim.c.x)
		{
			printf("(%i, %i)\n", cur.pos.c.x, cur.pos.c.y);fflush(stdout); /* <- */
			if (is_ok(&cur, &map) && back_track(tetrimini, length, apply(map, &cur), i + 1))
				return (1);
			cur.pos.c.x++;
		}
		cur.pos.c.y++;
	}
	return (0);
}

int				fi_solve(t_tet tetrimini[26], int *const side, int const length)
{
	*side = guess_what(length);
	printf("Starting with : %i\n", *side);
	while (!back_track(tetrimini, length,
		(t_map){*side, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}, 0))
	{
		printf("Restarting with : %i\n", *side);
		(*side)++;
	}
	return (0);
}
