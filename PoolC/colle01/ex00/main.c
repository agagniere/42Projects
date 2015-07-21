/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/19 12:17:01 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/19 23:00:52 by hcorrale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		main(int argc, char **argv)
{
	int **tab;
	int rep;

	tab = ft_create_table();
	if (argc == 10 && tab != NULL && is_valid(argv))
	{
		rep = ft_init_tab(&tab, argv);
		if (rep == 0)
		{
			ft_backtrack(tab, 0, &rep);
			if (rep == 1)
			{
				ft_backtrack_bis(tab, 0);
				draw(tab);
				return (0);
			}
		}
	}
	write(1, "Erreur\n", 7);
	return (0);
}
