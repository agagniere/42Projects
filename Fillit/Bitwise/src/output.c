/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 22:33:45 by angagnie          #+#    #+#             */
/*   Updated: 2016/01/22 20:05:21 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		print_already(char buffer[144], int side)
{
	int		i;

	i = 0;
	while (i < side)
	{
		write(1, buffer + i * 12, side);
		write(1, "\n", 1);
		i++;
	}
}

static void		draw_one(char *buf, t_tet const *const pce, int index)
{
	int		col;
	int		row;
	int		mask;

	row = 4;
	while (row-- > 0)
	{
		col = pce->pos.c.x;
		mask = 1;
		while (mask)
		{
			if (pce->line[row] & mask)
				buf[(row + pce->pos.c.y) * 12 + col] = 'A' + index;
			mask <<= 1;
			col++;
		}
	}
}

int				fi_print(t_tet const tetrimini[26],
	int const side, int const length)
{
	char	buffer[144];
	int		i;

	i = 144;
	while (i-- > 0)
		buffer[i] = '.';
	i = 0;
	while (i < length)
	{
		draw_one(buffer, tetrimini + i, i);
		i++;
	}
	print_already(buffer, side);
	return (0);
}
