/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle_00_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaignel <llaignel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/26 11:15:15 by llaignel          #+#    #+#             */
/*   Updated: 2015/07/26 12:58:56 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super.h"

char	colle_00_0(t_coord *point, t_coord *total)
{
	if (point->y == 0 || point->y == total->y - 1)
	{
		if (point->x == 0 || point->x == total->x - 1)
			return ('o');
		else
			return ('-');
	}
	else
	{
		if (point->x == 0 || point->x == total->x - 1)
			return ('|');
		else
			return (' ');
	}
}
