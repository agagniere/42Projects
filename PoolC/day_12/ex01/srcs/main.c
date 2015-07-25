/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 15:04:20 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/24 23:24:03 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super.h"

int		main(int ac, char **av)
{
	int k;

	k = 0;
	if (ac == 1)
		ft_display_stdin();
	else
	{
		while (++k < ac)
		{
			if (av[k][0] == '-')
				ft_display_stdin();
			else
				ft_display_file(av[k], av[0]);
		}
	}
	return (0);
}
