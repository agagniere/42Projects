/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/19 22:33:45 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/19 23:03:19 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_try_line(int **tab, int y, int nb)
{
	int x;

	x = -1;
	while (++x < 9)
		if (tab[y][x] == nb)
			return (1);
	return (0);
}

int		ft_try_col(int **tab, int x, int nb)
{
	int y;

	y = -1;
	while (++y < 9)
		if (tab[y][x] == nb)
			return (1);
	return (0);
}

int		ft_try_area(int **tab, int y, int x, int nb)
{
	int area[2];
	int i;
	int j;

	area[0] = y / 3;
	area[1] = x / 3;
	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
		{
			if (tab[area[0] * 3 + i][area[1] * 3 + j] == nb)
				return (1);
		}
	}
	return (0);
}

int		test(int **tab, int y, int x, int nb)
{
	return (ft_try_area(tab, y, x, nb)
	|| ft_try_line(tab, y, nb)
	|| ft_try_col(tab, x, nb));
}
