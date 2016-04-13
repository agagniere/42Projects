/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 12:41:58 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/14 17:19:01 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATRIX_H
# define FT_MATRIX_H

# define ORIGIN2 (t_point2){0,0}

typedef union	u_vect2
{
	struct
	{
		float	x;
		float	y;
	}			coord;
	float		table[2];
}				t_vect2;

typedef union	u_point2
{
	struct
	{
		size_t	x;
		size_t	y;
	}			coord;
	size_t		table[2];
}				t_point2;

typedef union	u_vect3
{
	struct
	{
		float	x;
		float	y;
		float	z;
	}			coord;
	float		table[3];
}				t_vect3;

typedef union	u_vect4
{
	struct
	{
		float	x;
		float	y;
		float	z;
		float	w;
	}			coord;
	float		table[4];
}				t_vect4;

typedef union	u_mat2x2
{
	t_vect2		col[2];
	float		table[4];
}				t_mat2x2;

typedef union	u_mat3x3
{
	t_vect3		col[3];
	float		table[9];
}				t_mat3x3;

typedef union	u_mat4x4
{
	t_vect4		col[4];
	float		table[16];
}				t_mat4x4;

#endif
