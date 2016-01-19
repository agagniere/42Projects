/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 22:33:45 by angagnie          #+#    #+#             */
/*   Updated: 2016/01/19 07:24:57 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
// ---
#include <stdio.h>
// ===

void	print_solution(char mapout[256], int side)
{
	int		i;
	char	*c;

	i = 0;
	while (i < side * side)
	{
		c = mapout + (16 * (i / side)) + i % side;
		// ----
		if (*c == '.')
			printf("\033[0m");
		else
			printf("\033[1;%im", 30 + ((*c - 'A') % 8));
		fflush(stdout);
		// ====
		write(1, c, 1);
		if (i % side == side - 1)
			write(1, "\n", 1);
		i++;
	}
}
