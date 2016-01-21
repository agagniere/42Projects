/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 22:33:45 by angagnie          #+#    #+#             */
/*   Updated: 2016/01/21 18:45:13 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		fi_print(t_tet const tetrimini[26], int const side, int const length)
{
	int			i;
	int			j;
	int			c;
	t_line		b;
	char		buffer[144];

	i = 0;
	while (i < length)
	{
		j = 4;
		while (j-- > 0)
		{
			b = 1;
			c = tetrimini[i].pos.c.x;
			while (b)
			{
				if (tetrimini[i].line[j] & b)
					buffer[(tetrimini[i].pos.c.y + j) * 12 + c] = 'A' + i;
				c++;
				b <<= 1;
			}
		}
		i++;
	}
	i = 0;
	while (i < side)
	{
		write(1, buffer + i * 12, side);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
