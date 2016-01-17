/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 10:42:22 by angagnie          #+#    #+#             */
/*   Updated: 2016/01/13 13:25:50 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define COORD(w, v, u) (tetrimini[w]->block[v].matrix[u]	\
						+ tetrimini[w]->pos.matrix[u])

int		is_ok(t_tetab tetrimini, t_i i)
{
	int				n;
	int				a;
	int				b;

	n = i;
	while (n-- > 0)
	{
		a = 4;
		while (a-- > 0)
		{
			b = 4;
			while (b-- > 0)
				if (COORD(i, a, 0) == COORD(n, b, 0)
					&& COORD(i, a, 1) == COORD(n, b, 1))
					return (0);
		}
	}
	return (1);
}
