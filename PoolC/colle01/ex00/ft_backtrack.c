/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/19 22:35:23 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/19 22:35:26 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

void	ft_backtrack(int **tab, int pos, int *ptr)
{
	int a;

	a = 0;
	if (pos == 81)
		*ptr = *ptr + 1;
	else
	{
		if (tab[pos / 9][pos % 9] == 0)
		{
			while (++a < 10)
				if (!test(tab, pos / 9, pos % 9, a))
				{
					tab[pos / 9][pos % 9] = a;
					ft_backtrack(tab, pos + 1, ptr);
					tab[pos / 9][pos % 9] = 0;
				}
		}
		else
			ft_backtrack(tab, pos + 1, ptr);
	}
}
