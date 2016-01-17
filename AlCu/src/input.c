/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 23:50:56 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/21 01:36:19 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aicu.h"

t_player	whosfirst(void)
{
	int		loop;
	char	*line;

	loop = 1;
	while (loop)
	{
		ft_putstr("Do you want to play first ? [y/n]\n");
		get_next_line(0, &line);
		loop = (*line != 'y' && *line != 'n');
	}
	return (*line == 'y' ? HUMAN : COMPUTER);
}

int			human_turn(t_ai *all)
{
	char	*line;
	int		loop;
	int		ans;

	loop = 1;
	ans = -1;
	while (loop > 0)
	{
		ft_putstr("How many matches would you like to remove ?\n");
		loop = get_next_line(0, &line);
		if ((loop == 1
			&& (ans = *line - '0')
			&& 0 < ans && ans < 4
			&& ans <= all->map[all->lines - 1]))
			loop = 0;
	}
	ft_putstr("You Removed ");
	ft_putnbr(ans);
	ft_putstr(" matche(s)\n");
	return (ans);
}
