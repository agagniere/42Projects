/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/11 10:11:02 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/12 10:28:59 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	sastantua(int size, char *brush);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		sastantua(atoi(av[1]), " /*|$\\");
	if (ac == 3)
		sastantua(atoi(av[1]), av[2]);
	return (0);
}
