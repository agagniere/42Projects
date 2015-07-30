/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 15:28:32 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/30 11:24:32 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super.h"

t_dim		*new_dim(t_int width, t_int height)
{
	t_dim	*ans;

	if (!(ans = (t_dim *)malloc(sizeof(t_dim))))
		malloc_fail();
	ans->width = width;
	ans->height = height;
	return (ans);
}

t_point		*new_point(t_int y, t_int x)
{
	t_point	*ans;

	if (!(ans = (t_point *)malloc(sizeof(t_point))))
		malloc_fail();
	ans->x = x;
	ans->y = y;
	return (ans);
}

t_max		*new_max(void)
{
	t_max		*ans;

	if (!(ans = (t_max *)malloc(sizeof(t_max))))
		malloc_fail();
	ans->value = 0;
	ans->x = 0;
	ans->y = 0;
	return (ans);
}

t_work		*new_work(char *str)
{
	char	*ptr;
	t_work	*ans;

	ptr = str;
	if (!(ans = (t_work *)malloc(sizeof(t_work))))
		malloc_fail();
	while (*ptr != '\0')
		ptr++;
	ans->map = new_dim(0, 0);
	ans->taken = *(--ptr);
	ans->obstacle = *(--ptr);
	ans->room = *(--ptr);
	*(ptr) = 'X';
	ans->map->height = ft_atoi(str);
	if (ans->map->height == 0 || ans->taken == ans->room
		|| ans->taken == ans->obstacle || ans->room == ans->obstacle)
		return (0);
	ans->max = new_max();
	ans->cur_line = 0;
	ans->to_be_skipped = 0;
	return (ans);
}
