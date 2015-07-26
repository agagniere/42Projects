/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/26 22:40:13 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/26 23:43:11 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super.h"

char	triangle_b(t_coord *point, t_coord *total)
{
	if (point->x == total->x - 1 || point->y == 0 || point->x  == point->y)
		return (NOT_A_SPACE);
	else
		return (' ');
}
