/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 09:37:48 by angagnie          #+#    #+#             */
/*   Updated: 2016/01/13 09:54:27 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
** | guess_what :	[| 1 ; 26 |]   ->	[| 2 ; 11 |]
** |				length		  |->	side
** |
** | side being the smallest natural integer verifying :
** |	length * 4 <= side * side
*/
static t_i	guess_what(t_i length)
{
	t_i			side;
	t_i const	cmp = length * 4;

	side = 2;
	while (side * side < cmp)
		side++;
	return (side);
}
