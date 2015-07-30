/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 11:32:07 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/30 15:53:05 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super.h"

#define TMPFILE "stdin.txt"

int		main(int ac, char **av)
{
	int		i;

	if (ac == 1)
	{
		copy_stdin(TMPFILE);
		if (ft_bsq(TMPFILE) == EXIT_KO)
			write(2, "map error\n", 10);
	}
	else
	{
		i = 0;
		while (++i < ac)
			if (ft_bsq(av[i]) == EXIT_KO)
				write(2, "map error\n", 10);
	}
	return (0);
}
