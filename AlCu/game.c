/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 23:50:05 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/21 01:47:12 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

static int		ai_turn(t_ai *all)
{
	int			i;
	int	const	last = all->lines - 1;

	i = (all->map[last] + 3 * (!all->inverted[last])) % 4;
	i += (i == 0);
	ft_putstr(". . .\nThe computer removed ");
	ft_putnbr(i);
	ft_putstr(" matche(s)\n");
	return (i);
}

void			play(t_ai *all)
{
	t_player	player;

	player = whosfirst();
	while (all->lines > 0)
	{
		if (player == COMPUTER)
			write(1, "\033[1J\033[H", 7);
		print_board(all);
		all->map[all->lines - 1] -= (player == HUMAN ?
			human_turn(all) : ai_turn(all));
		if (all->map[all->lines - 1] == 0)
			all->lines--;
		player = !player;
	}
	result(player);
}
