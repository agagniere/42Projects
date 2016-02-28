/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 05:38:03 by angagnie          #+#    #+#             */
/*   Updated: 2016/02/28 23:48:43 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"

static int		is_valid(t_domino *d, t_env *e)
{
	int		cpt;
	int		i;

	i = 9;
	cpt = 0;
	if (d->pos.x < 3 || d->pos.x > e->board_dim.width - 3 ||
		d->pos.y < 3 || d->pos.y > e->board_dim.height - 3)
		return (0);
	return (1);
}

static int		aux(t_env *e, t_domino *andy, t_domino *t, int i)
{
	t_pnt		offset;
	int			s;

	s = -1;
	while (++s < 1)
	{
		offset.x = (s ? 1 : 3) * (t->ori - 1)
			* (2 * t->dir - 3) * (i % 2 ? -1 : 1)
			+ (t->ori - 2) * s * 2;
		offset.y = (s ? 1 : 3) * (t->ori - 2)
			* (2 * t->dir - 3) * (i % 2 ? -1 : 1)
			+ (t->ori - 1) * s * 2;
		andy->pos.x = t->pos.x + offset.x;
		andy->pos.y = t->pos.y + offset.y;
		andy->ori = t->ori;
		andy->dir = (i % 2 ? t->dir : -t->dir);
		if (is_valid(andy, e))
			break ;
	}
	return (s);
}

static int		make_move(t_env *e, t_domino **hand)
{
	int			y;
	int			i;
	t_domino	*t;

	i = 56;
	while (i-- > 0)
		if (e->dom[i / 2].state == 3
			&& e->dom[i / 2].u[i % 2] == 0
			&& (y = -1))
			while (hand[++y] && (t = e->dom + i / 2))
				if (hand[y]->v[0] == t->v[i % 2]
					|| (hand[y]->v[1] == t->v[i % 2]
						&& (hand[y]->v[1] = hand[y]->v[0]) < 7
						&& (hand[y]->v[0] = t->v[i % 2]) < 7))
				{
					if (aux(e, hand[y], t, i) == 2)
						continue ;
					hand[y]->state = 3;
					hand[y]->u[0] = 1;
					t->u[i % 2] = 1;
					return (y);
				}
	return (-1);
}

static void		bullshit(t_env *e)
{
	if (e->stack_size && e->my_last_action == 1 && e->opp_last_action == 1)
		ft_putstr("draw\n");
	else
		ft_putstr("sulk\n");
}

void			play(t_env *e)
{
	t_domino	*hand[28];
	int			move;

	fill_hand(e, hand);
	if (*hand)
	{
		if (e->put_count > 1)
			move = make_move(e, hand);
		else if (e->put_count == 1)
			move = second_move(e, hand);
		else
			move = first_move(e, hand);
	}
	else
		move = -1;
	if (move >= 0 && move < 28)
	{
		put(hand[move], e->put_count);
		put_to_board(e, hand[move]);
		e->hand_size--;
	}
	else
		bullshit(e);
}
