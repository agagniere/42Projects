/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 13:23:06 by angagnie          #+#    #+#             */
/*   Updated: 2016/04/17 14:22:11 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa_base(int value, int base);

int		main(int ac, char **av)
{
	int		n;
	int		b;

	if (ac > 1)
		n = atoi(av[1]);
	else
		n = -2147483648;
	if (ac > 2)
		b = atoi(av[2]);
	else
		b = 10;
	printf("Le nombre %i en base %i : %s\n", n, b, ft_itoa_base(n, b));
	return (0);
}
