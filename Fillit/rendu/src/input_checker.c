/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 18:21:58 by angagnie          #+#    #+#             */
/*   Updated: 2016/01/18 22:42:17 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	fi_overall(char *buf)
{
	int		i;
	int		j;
	int		n;
	int		c;

	i = 4;
	n = 0;
	c = 0;
	while (i-- > 0)
	{
		j = 3;
		while (j-- > 0)
		{
			if (buf[5 * i + j] == '#' && buf[5 * i + j + 1] == '#')
				c++;
			if (buf[5 * j + i] == '#' && buf[5 * (j + 1) + i] == '#')
				c++;
		}
	}
	i = 20;
	while (i-- > 0)
		if (buf[i] == '#')
			n++;
	return (n != 4 || (c != 4 && c != 3));
}

static void	trim(t_i *p)
{
	int i;

	while (*p == 0)
	{
		i = 0;
		while (++i < 4)
			p[i - 1] = p[i];
		p[3] = 0;
	}
	while (!(p[0] % 2) && !(p[1] % 2) && !(p[2] % 2) && !(p[3] % 2))
	{
		i = 4;
		while (i-- > 0)
			p[i] >>= 1;
	}
}

int			fi_check(char buffer[21], t_reader *all)
{
	all->c = 0;
	while (all->c < all->ret)
	{
		if (all->c % 5 == 4 || all->c == 20)
		{
			if (buffer[all->c] != '\n')
				return (2);
		}
		else if ((buffer[all->c] != '#' && buffer[all->c] != '.'))
			return (1);
		else if (buffer[all->c] == '#')
			all->out[all->index][all->c / 5] |= 1 << all->c % 5;
		all->c++;
	}
	trim(all->out[all->index]);
	return (fi_overall(buffer));
}
