/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 02:42:00 by angagnie          #+#    #+#             */
/*   Updated: 2016/02/28 23:27:36 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"

static void		init_dominoes(t_env *e)
{
	int		i;
	int		j;
	int		a;

	a = 0;
	i = 7;
	while ((j = i--) > 0)
		while (j-- > 0)
			e->dom[a++] = (t_domino){{i, j}, {0, 0, 0, 0}, 0, {-1, -1}, 0, 0};
}

static void		init_env(t_env *e)
{
	e->player_num = 0;
	e->board_dim = (t_dim){1, 1};
	e->board = 0;
	e->hand_size = 0;
	e->stack_size = 28;
	e->put_count = 0;
	e->my_last_action = -1;
	e->opp_last_action = -1;
	e->povbool = 0;
}

int				main(void)
{
	t_env e;

	init_env(&e);
	init_dominoes(&e);
	return (input_loop(&e));
}
