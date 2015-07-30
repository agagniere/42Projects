/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 22:19:44 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/30 14:15:25 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef int					t_bool;
typedef unsigned int		t_int;
typedef struct				s_max
{
	t_int	value;
	t_int	x;
	t_int	y;
}							t_max;
typedef struct				s_dim
{
	t_int	width;
	t_int	height;
}							t_dim;
typedef struct				s_point
{
	t_int	x;
	t_int	y;
}							t_point;
typedef struct				s_work
{
	t_int	to_be_skipped;
	t_dim	*map;
	char	obstacle;
	char	room;
	char	taken;
	t_int	*cur_line;
	t_max	*max;
}							t_work;

#endif
