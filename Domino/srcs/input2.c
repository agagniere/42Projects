/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 23:38:37 by angagnie          #+#    #+#             */
/*   Updated: 2016/02/28 23:40:28 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"

void	find_hook(t_env *e, t_domino *t)
{
	int		i;
	t_pnt	ctr;

	i = 4;
	while (i-- > 2)
	{
		ctr = (t_pnt){t->pos.x + i * (t->ori - 1) * (2 * t->dir - 3),
						t->pos.y + i * (t->ori - 2) * (2 * t->dir - 3)};
		if (BOARD(ctr.x, ctr.y) == '-' || BOARD(ctr.x, ctr.y) == '|')
			break ;
	}
	if (i == 1 && (i = 6))
		while (i-- > 2)
		{
			ctr = (t_pnt){t->pos.x + (t->ori - 1) * (2 * t->dir - 3) * i / 2
							+ (t->ori - 2) * (3 - i / 2) * (i % 2 ? 1 : -1),
							t->pos.y + (t->ori - 2) * (2 * t->dir - 3) * i / 2
							+ (t->ori - 1) * (3 - i / 2) * (i % 2 ? 1 : -1)};
			if (BOARD(ctr.x, ctr.y) == '-' || BOARD(ctr.x, ctr.y) == '|')
				break ;
		}
	i = 0;
	while (e->dom[i].pos.x != ctr.x || e->dom[i].pos.y != ctr.y)
		i++;
	e->dom[i].u[1] = 1;
}

void	new_piece(t_env *e, char *str)
{
	t_domino	t;
	int			i;

	t.v[0] = ft_atoi(str);
	t.v[1] = ft_atoi((str += 2));
	t.pos.x = ft_atoi((str += 2));
	while (*str++ != ':')
		;
	t.pos.y = ft_atoi(str);
	while (*str++ != ':')
		;
	aux(&t, str);
	if (e->put_count)
		find_hook(e, &t);
	e->put_count++;
	i = 28;
	put_to_board(e, &t);
	while (i-- > 0)
		if ((e->dom[i].v[0] == t.v[0] && e->dom[i].v[1] == t.v[1])
			|| (e->dom[i].v[0] == t.v[1] && e->dom[i].v[1] == t.v[0]))
		{
			memcpy(e->dom + i, &t, sizeof(t_domino));
			e->dom[i].state = 3;
			break ;
		}
}
