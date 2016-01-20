/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 22:33:45 by angagnie          #+#    #+#             */
/*   Updated: 2016/01/19 09:31:55 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_solution(char mapout[256], int side)
{
	int		i;
	char	*c;

	i = 0;
	while (i < side * side)
	{
		c = mapout + (16 * (i / side)) + i % side;
		write(1, c, 1);
		if (i % side == side - 1)
			write(1, "\n", 1);
		i++;
	}
}
