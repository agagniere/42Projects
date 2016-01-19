/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 22:33:45 by angagnie          #+#    #+#             */
/*   Updated: 2016/01/19 02:00:08 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_solution(char mapout[256], int side)
{
	int		i;
	char	*c;
#ifdef COLOR
	char	str[12] = "\033[1;31m";
#endif

	i = 0;
	while (i < side * side)
	{
		c = mapout + (16 * (i / side)) + i % side;
#ifdef COLOR
		str[6] = '0' + ((*c - 'A') % 8);
		write(1, str, 10);
#endif
		write(1, c, 1);
		if (i % side == side - 1)
			write(1, "\n", 1);
		i++;
	}
	write(1, "\033[0m", 5);
}
