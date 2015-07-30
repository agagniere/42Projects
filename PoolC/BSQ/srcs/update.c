/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 22:55:03 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/30 11:16:40 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super.h"

void	update_max(t_max *max, t_int value, t_point *p)
{
	max->value = value;
	max->x = p->x;
	max->y = p->y;
}

void	update_work_length(t_work *work)
{
	t_int i;

	if (!(work->cur_line = (t_int *)malloc(sizeof(t_int) * work->map->width)))
		malloc_fail();
	i = 0;
	while (i < work->map->width)
	{
		work->cur_line[i] = 0;
		i++;
	}
}
