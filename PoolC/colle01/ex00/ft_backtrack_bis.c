/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack_bis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/19 13:06:14 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/19 22:40:46 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int	ft_backtrack_bis(int **tab, int pos)
{
	int y;
	int x;
	int nb;

	if (pos == 81)
		return (1);
	y = pos / 9;
	x = pos % 9;
	if (tab[y][x] != 0)
		return (ft_backtrack_bis(tab, pos + 1));
	nb = 1;
	while (nb <= 9)
	{
		tab[y][x] = 0;
		if (!test(tab, y, x, nb))
		{
			tab[y][x] = nb;
			if (ft_backtrack_bis(tab, pos + 1))
				return (1);
		}
		++nb;
	}
	tab[y][x] = 0;
	return (0);
}
