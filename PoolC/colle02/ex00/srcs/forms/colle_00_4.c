/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle_00_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaignel <llaignel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/26 14:12:25 by llaignel          #+#    #+#             */
/*   Updated: 2015/07/26 22:12:00 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super.h"

char	colle_00_4(t_coord *point, t_coord *total)
{
	if (point->y == 0 && point->x == 0)
		return ('A');
	else if ((point->y == total->y - 1 && point->x == 0)
		|| (point->y == 0 && point->x == total->x - 1))
		return ('C');
	else if (point->y == total->y - 1
			&& point->x == total->x - 1)
		return ('A');
	else if (point->y == 0 || point->x == 0
		|| point->y == total->y - 1 || point->x == total->x - 1)
		return ('B');
	else
		return (' ');
}
