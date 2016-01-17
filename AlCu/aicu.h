/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aicu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaitalla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 13:52:16 by yaitalla          #+#    #+#             */
/*   Updated: 2016/01/07 12:49:31 by sid              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AICU_H
# define AICU_H
# define MAX_ROW 1024

# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct		s_ai
{
	int				*map;
	int				*inverted;
	int				lines;
}					t_ai;

typedef enum		e_player
{
	HUMAN,
	COMPUTER
}					t_player;

int					initall(t_ai *all, int fd);
void				play(t_ai *all);
t_player			whosfirst(void);
int					human_turn(t_ai *all);
void				result(t_player who);
void				print_board(t_ai *all);
void				putcolor(char const *str, char const *color, int fd);

#endif
