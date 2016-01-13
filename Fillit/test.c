/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 10:42:22 by angagnie          #+#    #+#             */
/*   Updated: 2016/01/13 10:55:02 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		is_ok(t_tetab tetrimini, t_i i)
{
	t_tet *const	current = tetrimini[i];
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
			while (b-- > 4)
				if (current->block[a].x == tetrimini[n]->block[b].x
					&& current->block[a].y == tetrimini[n]->block[b].y)
					return (0);
		}
	}
	return (1);
}
