/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 21:48:05 by angagnie          #+#    #+#             */
/*   Updated: 2016/01/20 17:59:36 by angagnie         ###   ########.fr       */
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
	return (!(cur[0] & mapbool[row])
		&& !(cur[1] & mapbool[row + 1])
		&& !(cur[2] & mapbool[row + 2])
		&& !(cur[3] & mapbool[row + 3]));
}

static int	backtrack(t_tet tetrimini[26], int const length, int const side, int i, t_map map)
{
	if (i == length)
		return (1);
	while (tetrimini[i])
	return (0);
}

int		fi_solve(t_tet tetrimini[26], int *const side, int const length)
{
	*side = guess_what(length);
	while (!back_track(tetrimini, length, (t_map){*side, {0, 0, 0}}, 0))
		(*side)++;
	return (1);
}
