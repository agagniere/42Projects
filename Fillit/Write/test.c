/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 10:42:22 by angagnie          #+#    #+#             */
/*   Updated: 2016/01/13 15:59:36 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define GET(w) pos->matrix[w] + current->block[n].matrix[w]

int		is_ok(t_tet const *const current, t_pnt const *const pos,
	char const *const map, t_i const side)
{
	t_i		n;

	n = 4;
	while (n-- > 0)
		if (map[side * (GET(1)) + GET(0)] != '.')
			return (0);
	return (1);
}
