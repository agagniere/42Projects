/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/26 23:05:49 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/26 23:42:31 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "super.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int ac, char **av)
{
	t_coord p, m;

	if (ac == 3)
	{
		m.x = atoi(av[1]);
		m.y = atoi(av[2]);
		p.y = 0;
		while (p.y < m.y)
		{
			p.x = -1;
			while (++p.x < m.x)
				ft_putchar(triangle_b(&p, &m));
			p.y++;
			if (m.x > 0)
				ft_putchar('\n');
		}
	}
	return (0);
}
