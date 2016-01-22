/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 15:27:44 by angagnie          #+#    #+#             */
/*   Updated: 2016/01/22 19:39:44 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

/*
** neither a char nor an unsigned char
** u_short or u_int or u_long_...
*/
typedef unsigned short	t_line;

typedef union			u_vec2i
{
	int					m[2];
	struct
	{
		int				x;
		int				y;
	}					c;
}						t_vec2i;

typedef struct			s_tet
{
	t_line				line[4];
	t_vec2i				pos;
	t_vec2i				dim;
}						t_tet;

typedef struct			s_map
{
	int					side;
	t_line				line[12];
}						t_map;

#endif
