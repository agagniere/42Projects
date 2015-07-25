/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 15:04:20 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/24 23:38:37 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super.h"

int		main(int ac, char **av)
{
	int k;
	int c;

	k = 0;
	c = -27315;
	if (ac == 1)
		ft_display_stdin();
	else if (av[1][0] == '-' && av[1][1] == 'c')
	{
		if (av[1][2])
			c = ft_atoi(av[1] + 2);
		else
			c = ft_atoi(av[2]);
	}
	else
	{
		while (++k < ac)
		{
			if (av[k][0] == '-')
				ft_display_stdin();
			else
				ft_display_file(av[k], av[0], c);
		}
	}
	return (0);
}
