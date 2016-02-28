/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   domino.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 23:16:19 by tbeauman          #+#    #+#             */
/*   Updated: 2016/02/28 23:46:55 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOMINO_H
# define DOMINO_H

# include <unistd.h>
# include "libft.h"
# include "get_next_line.h"
# include "typedefs.h"
# define BOARD(x,y) e->board[(y) * e->board_dim.width + x]

int		init_board(t_env *e);
int		input_loop(t_env *e);
void	play(t_env *e);
void	put_to_board(t_env *e, t_domino *d);
void	print_board(t_env *e);
void	find_hook(t_env *e, t_domino *t);
void	new_piece(t_env *e, char *str);
int		second_move(t_env *e, t_domino **hand);
void	put(t_domino *d, int move_count);
void	fill_hand(t_env *e, t_domino **hand);
int		first_move(t_env *e, t_domino **hand);

#endif
