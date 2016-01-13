/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 15:24:09 by angagnie          #+#    #+#             */
/*   Updated: 2016/01/13 09:51:24 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

/*
** int or char or unsigned ...
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
	t_pnt	pos;
	t_dim	dim;
}				t_tet;

void			solve(t_tet* tetrimini, t_i length);


#endif
