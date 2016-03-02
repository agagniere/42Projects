/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 05:27:33 by angagnie          #+#    #+#             */
/*   Updated: 2016/03/02 20:17:19 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"

static void		receive_pieces(t_env *e, int n)
{
	char	*buf;
	int		v[2];
	int		d;

	if (!e->povbool++)
		e->stack_size -= 2 * n;
	e->hand_size += n;
	while (n-- > 0)
	{
		get_next_line(0, &buf);
		v[0] = ft_atoi(buf + 6);
		v[1] = ft_atoi(buf + 8);
		d = 28;
		while (d-- > 0)
		{
			if ((v[0] == e->dom[d].v[0] && v[1] == e->dom[d].v[1])
				|| (v[0] == e->dom[d].v[1] && v[1] == e->dom[d].v[0]))
			{
				e->dom[d].state = 1;
				break ;
			}
		}
	}
}

static void		last_move(t_env *e, char *str)
{
	int		n;
	int		r;

	n = ft_atoi(str);
	while (*str++ != ':')
		;
	if (!(ft_strncmp(str, "put", 3)))
		r = 0;
	else if (!(ft_strncmp(str, "draw", 4)))
	{
		r = 2;
		e->stack_size--;
	}
	else if (!(ft_strncmp(str, "sulk", 4)))
		r = 1;
	else if (!(ft_strncmp(str, "ko", 2)))
		r = 3;
	else
		r = -1;
	if (n == e->player_num)
		e->my_last_action = r;
	else
		e->opp_last_action = r;
}

static int		niklapolice(char *buf, t_env *e)
{
	e->board_dim.width = ft_atoi(buf);
	while (*buf++ != ':')
		;
	e->board_dim.height = ft_atoi(buf);
	if (e->board)
		free(e->board);
	return (init_board(e));
}

int				input_loop(t_env *e)
{
	char	*b;

	while (get_next_line(0, &b) > 0)
	{
		if (!(ft_strncmp(b, "player:n:", 9)))
			e->player_num = ft_atoi(b + 9);
		else if (!(ft_strncmp(b, "board:", 6)) && niklapolice(b + 6, e))
			return (1);
		else if (!(ft_strncmp(b, "pieces:n:", 9)))
			receive_pieces(e, ft_atoi(b + 9));
		else if (!(ft_strncmp(b, "go", 2)))
			play(e);
		else if (!(ft_strncmp(b, "end:winner:", 11)))
			break ;
		else if (!(ft_strncmp(b, "p:", 2)))
			last_move(e, b + 2);
		else if (!(ft_strncmp(b, "sulk:", 5)) || !(ft_strncmp(b, "draw:", 5)))
			last_move(e, b + 5);
		else if (!(ft_strncmp(b, "new:", 4)))
			new_piece(e, b + 4);
	}
	if (e->board)
		free(e->board);
	return (0);
}
