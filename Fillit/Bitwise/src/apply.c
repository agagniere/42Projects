/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 23:26:56 by angagnie          #+#    #+#             */
/*   Updated: 2016/01/19 01:37:23 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fi_apply(t_map *map, t_i cur[4], int row, int i)
{
	int		a;
	int		b;
	int		c;

	a = 4;
	while (a-- > 0)
	{
		b = cur[a];
		c = 0;
		map->bool[row + a] |= b;
		while (b)
		{
			if ((b % 2))
				map->out[16 * (row + a) + c] = 'A' + i;
			c++;
			b >>= 1;
		}
	}
}

void	fi_remove(t_map *map, t_i cur[4], int row)
{
	int		a;
	int		b;
	int		c;

	a = 4;
	while (a-- > 0)
	{
		b = cur[a];
		map->bool[row + a] ^= b;
		c = 0;
		while (b)
		{
			if (b % 2)
				map->out[16 * (row + a) + c] = '.';
			c++;
			b >>= 1;
		}
	}
}
