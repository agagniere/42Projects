/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 18:21:58 by angagnie          #+#    #+#             */
/*   Updated: 2016/01/18 21:05:06 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// --
#include <stdio.h>
// --

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
		all->c++;
	}
	return (fi_overall(buffer));
}