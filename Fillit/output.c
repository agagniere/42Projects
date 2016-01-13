/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 11:08:29 by angagnie          #+#    #+#             */
/*   Updated: 2016/01/13 11:54:08 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define BLOCK(v) (tetrimini[n]->block[i].matrix[v])

void            print_solution(t_tetab tetrimini, t_i const length,
							   t_i const side)
{
	t_i		n;
	t_i		i;
	char	buffer[side * side];


	printf("Solution found : \n\tlength = %i\n\tside = %i\n", length, side);
	n = length;
	i = side * side;
	while (i-- > 0)
		buffer[i] = ' ';
	while (n-- > 0)
	{
		i = 4;
		while (i-- > 0)
			buffer[BLOCK(1) * side +  BLOCK(0)] = 'A' + n;
	}
	n = 0;
	ft_print_memory(buffer, side * side);
	while (n < side)
	{
		write(1, buffer + side * n, side);
		write(1, "\n", 1);
		n++;
	}
}
