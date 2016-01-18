/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 15:24:09 by angagnie          #+#    #+#             */
/*   Updated: 2016/01/19 00:09:42 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

/*
** neither a char nor an unsigned char
** u_short or u_int or u_long_...
*/
typedef unsigned short	t_i;

/*
** ret		: read returned value
** index	: current index in the tetrimini list
** out		: the tetrimini list
** c		: position in the buffer
*/
typedef struct			s_reader
{
	int			ret;
	int			index;
	t_i			out[26][4];
	int			c;
}						t_reader;

typedef struct			s_map
{
	t_i			bool[16];
	char		out[256];
}						t_map;

int						fi_check(char buffer[21], t_reader *all);
void					init(t_i tetrimini[26][4], int len);

void					print_solution(t_map map, int side);
void					fi_apply(t_map *map, t_i cur[4], int row, int i);
void					fi_remove(t_map *map, t_i cur[4], int row);

#endif
