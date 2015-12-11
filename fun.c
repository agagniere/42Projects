/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 20:05:20 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/11 21:27:48 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#define SAVE "\033[s"
#define UNSAVE "\033[u"

int		main(int ac, char **av)
{
	int row;
	int col;
	char buf[1024];
	int r;

	write(1, "\033[30;1H", 7);
	write(1, "\033[1J", 5);
	write(1, SAVE, 3);
	col = 0;
	while (col < ac)
	{
		row = 0;
		while (av[col][row] != '\0')
		{
			printf("%s%i;%iH%c", "\033[", row  + 1, 2 *col + 1, av[col][row]);
			fflush(stdout);
			row++;
		}
		col++;
	}
//	write(1, "\033[1;9r", 6);
	write(1, UNSAVE, 3);
	return (0);
}
