/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/26 22:40:13 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/26 23:17:17 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super.h"

char	rectangle(t_coord *point, t_coord *total)
{
	if (point->x == 0 || point->y == 0 || point->x == total->x - 1
		|| point->y == total->y - 1)
		return (NOT_A_SPACE);
	else
		return (' ');
}
