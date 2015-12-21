/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaitalla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 16:39:24 by yaitalla          #+#    #+#             */
/*   Updated: 2015/12/21 01:49:03 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

static int			max_index(t_ai *all)
{
	int ans;
	int i;

	i = 0;
	ans = 0;
	while (++i < all->lines)
		if (all->map[i] > all->map[ans])
			ans = i;
	return (ans);
}

void				result(t_player who)
{
	if (who == HUMAN)
		putcolor("Congratulations, you won !!!", BOLD_GREEN, 1, 1);
	else
		putcolor("Sorry, you lost...", BOLD_RED, 1, 1);
}

void				print_board(t_ai *all)
{
	int row;
	int col;
	int max;

	row = -1;
	max = all->map[max_index(all)];
	write(1, "\033[0;33m", 7);
	while (++row < all->lines)
	{
		if (row == all->lines - 1)
			write(1, "\033[1;33m", 7);
		col = 0;
		while (col++ < max / 2 - all->map[row] / 2)
			write(1, " ", 1);
		col = 0;
		while (col++ < all->map[row])
			write(1, "|", 1);
		write(1, "\n", 1);
	}
	write(1, "\033[0m", 4);
}
