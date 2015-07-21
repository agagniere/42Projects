/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/19 13:24:46 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/19 22:47:15 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		**ft_create_table(void)
{
	int i;
	int **tab;

	i = -1;
	tab = (int **)malloc(sizeof(int *) * 9);
	while (++i < 9)
		tab[i] = (int *)malloc(sizeof(int) * 9);
	return (tab);
}

int		ft_god_number(int **tab)
{
	int i;
	int pos;

	pos = -1;
	i = 0;
	while (++pos != 81)
	{
		if (tab[pos / 9][pos % 9] != 0)
			++i;
	}
	return (i);
}

int		ft_init_tab(int ***list, char **argv)
{
	int pos;
	int i;
	int j;

	*list = ft_create_table();
	pos = -1;
	while (++pos || 1)
	{
		i = pos / 9;
		j = pos % 9;
		if (pos == 81)
			return (ft_god_number(*list) < 17);
		if (argv[i + 1][j] == '.')
			(*list)[i][j] = 0;
		else if ((argv[i + 1][j] >= '0') && (argv[i + 1][j] <= '9'))
			(*list)[i][j] = (int)(argv[i + 1][j] - 48);
		else
			return (1);
	}
	return (1);
}
