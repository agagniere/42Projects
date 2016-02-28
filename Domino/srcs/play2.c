/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 23:47:19 by angagnie          #+#    #+#             */
/*   Updated: 2016/02/28 23:48:19 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"

void		put(t_domino *d, int move_count)
{
	ft_putstr("put:");
	ft_putnbr(d->v[0]);
	ft_putchar(':');
	ft_putnbr(d->v[1]);
	if (move_count)
	{
		ft_putchar(':');
		ft_putnbr(d->pos.x + (d->ori - 1) * (2 * d->dir - 3));
		ft_putchar(':');
		ft_putnbr(d->pos.y + (d->ori - 2) * (2 * d->dir - 3));
		ft_putchar(':');
		ft_putnbr(d->ori);
		ft_putchar(':');
		ft_putnbr(d->dir);
	}
	ft_putchar('\n');
}

void		fill_hand(t_env *e, t_domino **hand)
{
	int		i;

	i = 28;
	while (i-- > 0)
		if (e->dom[i].state == 1)
			*hand++ = e->dom + i;
	*hand = 0;
}

int			first_move(t_env *e, t_domino **hand)
{
	int	y;
	int	move;

	y = -1;
	move = -1;
	while (hand[++y])
		if (hand[y]->v[0] == hand[y]->v[1]
			&& (move = y) > -1
			&& hand[y]->v[0] == 5)
			break ;
	if (move < 0)
		return (-1);
	hand[move]->pos.x = e->board_dim.width / 2;
	hand[move]->pos.y = e->board_dim.height / 2;
	hand[move]->ori = HORI;
	hand[move]->dir = DOWN_RIGHT;
	hand[move]->state = 3;
	return (move);
}

int			second_move(t_env *e, t_domino **hand)
{
	int		y;
	int		v;
	int		move;

	move = -1;
	v = BOARD(e->board_dim.width / 2 + 1, e->board_dim.height / 2) - '0';
	y = -1;
	while (hand[++y])
	{
		if ((hand[y]->v[0] == v) || (hand[y]->v[1] == v
									&& (hand[y]->v[1] = hand[y]->v[0]) < 7
									&& (hand[y]->v[0] = v) < 7))
		{
			move = y;
			if ((2 * v + hand[y]->v[1]) % 5 == 0)
				break ;
		}
	}
	hand[move]->pos.x = e->board_dim.width / 2;
	hand[move]->pos.y = e->board_dim.height / 2 - 2;
	hand[move]->ori = VERT;
	hand[move]->dir = UP_LEFT;
	hand[move]->state = 3;
	hand[move]->u[0] = 1;
	return (move);
}
