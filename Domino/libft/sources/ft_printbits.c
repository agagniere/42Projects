/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:39:29 by tbeauman          #+#    #+#             */
/*   Updated: 2015/11/27 17:42:10 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printbits(unsigned char octet)
{
	int		count;

	count = 8;
	while (count)
	{
		if (octet >= ft_power(2, count - 1))
		{
			ft_putchar('1');
			octet -= ft_power(2, count - 1);
		}
		else
			ft_putchar('0');
		count--;
	}
}
