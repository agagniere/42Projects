/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle_00_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/25 15:21:18 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/26 13:01:16 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super.h"

char	colle_00_1(t_coord *point, t_coord *total)
{
	if (point->y == 0 && point->x == 0)
		return ('/');
	else if ((point->y == total->y - 1 && point->x == 0)
		|| (point->y == 0 && point->x == total->x - 1))
		return ('\\');
	else if (point->y == total->y - 1 && point->x == total->x - 1)
		return ('/');
	else if (point->y == 0 || point->x == 0
		|| point->y == total->y - 1 || point->x == total->x - 1)
		return ('*');
	else
		return (' ');
}
