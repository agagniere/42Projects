/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/21 16:44:31 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/21 22:30:57 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super.h"

int		main(int ac, char **av)
{
	t_myint a;
	t_myint b;

	if (ac == 4)
	{
		a = 0;
		while (av[2][a])
			++a;
		a = ft_atoi(av[1]);
		b = ft_atoi(av[3]);
		compute(a, b, av[2][0]);
		ft_putchar('\n');
	}
	return (0);
}
