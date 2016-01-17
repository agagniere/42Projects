/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 15:24:09 by angagnie          #+#    #+#             */
/*   Updated: 2016/01/13 16:00:19 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <unistd.h>

/*
** int or short or char or unsigned ...
*/
typedef char	t_i;

typedef union	s_pnt
{
	t_i		matrix[2];
	struct
	{
		t_i	x;
		t_i	y;
	}		coord;
}				t_pnt;

typedef	struct	s_dim
{
	t_i		width;
	t_i		height;
}				t_dim;

typedef struct	s_tet
{
	t_pnt	block[4];
	t_dim	dim;
}				t_tet;

typedef t_tet *const *const t_tetab;

void			solve(t_tetab tetrimini, t_i const length);

void			print_solution(char *map, t_i side);

int				is_ok(t_tet const *const current, t_pnt const pos, char const *const map, t_i const side);

#endif
