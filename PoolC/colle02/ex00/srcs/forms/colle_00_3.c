/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle_00_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaignel <llaignel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/26 14:00:58 by llaignel          #+#    #+#             */
/*   Updated: 2015/07/26 22:26:26 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super.h"

char	colle_00_3(t_coord *point, t_coord *total)
{
	if (point->x == 0 && (point->y == 0 || point->y == total->y - 1))
		return ('A');
	else if (point->x == total->x - 1
		&& (point->y == 0 || point->y == total->y - 1))
		return ('C');
	else if (point->y == 0 || point->y == total->y - 1
		|| point->x == 0 || point->x == total->x - 1)
		return ('B');
	else
		return (' ');
}
