/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 18:21:58 by angagnie          #+#    #+#             */
/*   Updated: 2016/01/18 19:45:24 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	fi_spread(char *buf, int c, int i)
{
	int const	*ind[4] = {c - 5, c + 5, c - 1, c + 1};
	int const	*cond[4] = {c > 4, c < 15, c % 5 > 0, c % 5 < 4};
	int			tmp[4];
	int			i;

	i = 4;
	buf[c] = 'O';
	while (i-- > 0)
	{
		tmp[i] = 0;
		if (cond[i] && buf[ind[i]] == '#')
		{
			tmp[i] = 1;
			i += fi_spread(buf, ind[i], 1);
			buf[ind[i]] = 'O';
		}
	}
	i = 4;
	while (i-- > 0)
		if (tmp[i])
			buf[ind[i]] = '#';
	return (i);
}

int			fi_check(char buf[21], t_reader *all)
{
	all->c = 0;
	while (all->c < all->ret)
	{
		if (all->c % 5 == 4 || all->c == 20)
		{
			if (buffer[all->c] != '\n')
				return (1);
		}
		else if ((buffer[all->c] == '#' && spread(buffer, al->c, 1) != 4)
				|| (buffer[all->c] != '#' && buffer[all->c] != '.'))
			return (1);
		all->c++;
	}
	return (0);
}
