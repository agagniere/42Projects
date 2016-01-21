/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 15:24:09 by angagnie          #+#    #+#             */
/*   Updated: 2016/01/21 14:51:28 by angagnie         ###   ########.fr       */
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
typedef uint64_t		t_line;

typedef union			u_vec2i
{
	int		m[2];
	struct
	{
		int	x;
		int	y;
	}		c;
}						t_vec2i;

typedef struct			s_tet
{
	t_line		line[4];
	t_vec2i		pos;
	t_vec2i		dim;
}						t_tet;

typedef struct			s_map
{
	int			side;
	t_line		line[12];
}						t_map;

t_map		apply(t_map const m[1], t_line const line[4], t_vec2i const pos);


#endif
