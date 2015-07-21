/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/19 22:28:44 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/19 22:28:45 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		draw(int **tab)
{
	int x;
	int y;

	y = -1;
	while (++y < 9)
	{
		x = -1;
		while (++x < 9)
		{
			ft_putchar('0' + tab[y][x]);
			if (x == 8)
				ft_putchar('\n');
			else
				ft_putchar(' ');
		}
	}
	return (0);
}
