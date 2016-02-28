/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 03:18:58 by angagnie          #+#    #+#             */
/*   Updated: 2016/02/28 23:06:50 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"

int		init_board(t_env *e)
{
	int		i;

	i = e->board_dim.width * e->board_dim.height;
	if (!(e->board = (char *)malloc(sizeof(char) * i)))
		return (1);
	while (i-- > 0)
		e->board[i] = ' ';
	return (0);
}

void	put_to_board(t_env *e, t_domino *d)
{
	t_pnt	offset;

	offset = (t_pnt){(d->ori - 1) * (2 * d->dir - 3),
		(d->ori - 2) * (2 * d->dir - 3)};
	BOARD(d->pos.x, d->pos.y) = (d->dir == HORI ? '|' : '-');
	BOARD(d->pos.x + offset.x, d->pos.y + offset.y) = d->v[0] + '0';
	BOARD(d->pos.x - offset.x, d->pos.y - offset.y) = d->v[1] + '0';
}

void	print_board(t_env *e)
{
	int		row;

	row = 0;
	ft_putstr_fd("\t---=== Joueur ", 2);
	ft_putchar_fd('0' + e->player_num, 2);
	ft_putstr_fd(" ===---\n", 2);
	while (row < e->board_dim.height)
	{
		ft_putchar_fd('0' + row % 10, 2);
		ft_putchar_fd('|', 2);
		write(2, e->board + row * e->board_dim.width, e->board_dim.width);
		ft_putchar_fd('|', 2);
		ft_putchar_fd('a' + row % 26, 2);
		ft_putchar_fd('\n', 2);
		row++;
	}
}
