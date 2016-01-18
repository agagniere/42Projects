/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 15:24:09 by angagnie          #+#    #+#             */
/*   Updated: 2016/01/18 21:42:06 by angagnie         ###   ########.fr       */
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
typedef size_t	t_i;

/*
** ret		: read returned value
** index	: current index in the tetrimini list
** out		: the tetrimini list
** c		: position in the buffer
*/
typedef struct	s_reader
{
	int			ret;
	int			index;
	t_i			out[26][4];
	int			c;
}				t_reader;

int				fi_check(char buffer[21], t_reader *all);

//void			solve(t_tetab tetrimini, t_i const length);

//void			print_solution(char *map, t_i side);

//int				is_ok(t_tet const *const current, t_pnt const pos, char const *const map, t_i const side);

#endif
