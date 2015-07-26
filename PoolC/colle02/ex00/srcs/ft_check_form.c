/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_form.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yismail <yismail@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/26 02:31:53 by yismail           #+#    #+#             */
/*   Updated: 2015/07/26 23:26:19 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super.h"

t_bool	check_form(t_fun fct, char **tab, t_coord *max)
{
	t_coord		pos;

	pos.y = 0;
	while (pos.y < max->y)
	{
		pos.x = 0;
		while (pos.x < max->x)
		{
			if (fct(&pos, max) == NOT_A_SPACE)
			{
				if (tab[pos.y][pos.x] == ' ')
					return (FALSE);
			}
			else if (tab[pos.y][pos.x] != fct(&pos, max))
				return (FALSE);
			pos.x++;
		}
		pos.y++;
	}
	return (TRUE);
}
