/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 12:42:45 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/15 13:03:43 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	colle(int x, int y)
{
	int i;
	int j;

	j = -1;
	while (++j < y)
	{
		i = -1;
		while (++i < x)
			if ((i == 0 || i == x - 1) && (j == 0 || j == y - 1))
				ft_putchar('o');
			else if (i == 0 || i == x - 1)
				ft_putchar('|');
			else if (j == 0 || j == y - 1)
				ft_putchar('-');
			else
				ft_putchar(' ');
		if (x > 0)
		ft_putchar('\n');
	}
}

int		main(void)
{
	colle(5, 1);
	return (0);
}
