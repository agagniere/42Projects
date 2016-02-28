/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 23:57:57 by tbeauman          #+#    #+#             */
/*   Updated: 2016/02/28 22:53:28 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
# define TYPEDEFS_H

typedef struct	s_pnt
{
	int			x;
	int			y;
}				t_pnt;

typedef struct	s_dim
{
	int			width;
	int			height;
}				t_dim;

typedef enum	e_orien
{
	VERT = 1,
	HORI
}				t_orien;

typedef enum	e_direc
{
	UP_LEFT = 1,
	DOWN_RIGHT
}				t_direc;

typedef struct	s_domino
{
	int			v[2];
	int			u[4];
	int			state;
	t_pnt		pos;
	t_orien		ori;
	t_direc		dir;
}				t_domino;

/*
** ---=== States ===---
** 0 : unknown
** 1 : owned by ourselves
** 2 : owned by the other player
** 3 : On the board
** 4 : In the deck
** 12 : probably in the other player's hand
** 14 : probably in the deck
*/

typedef struct	s_env
{
	int			player_num;
	t_dim		board_dim;
	char		*board;
	int			hand_size;
	int			stack_size;
	int			put_count;
	int			my_last_action;
	int			opp_last_action;
	int			povbool;
	t_domino	dom[28];
}				t_env;

#endif
