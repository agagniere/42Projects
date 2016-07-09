/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt_bis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 22:43:40 by angagnie          #+#    #+#             */
/*   Updated: 2016/07/09 23:25:48 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Iterative version.
** No performance gain were noticed.
*/

int		ft_sqrt(int nb)
{
	const unsigned long n = nb;
	unsigned long		up;
	unsigned long		low;
	unsigned long		mid;
	unsigned long		sq;

	low = 1;
	up = n;
	if (nb == 1)
		return (1);
	while (nb > 1)
	{
		mid = (up + low) / 2;
		if (mid == low)
			return (0);
		sq = mid * mid;
		if (sq == n)
			return ((int)mid);
		else if (sq < n)
			low = mid;
		else
			up = mid;
	}
	return (0);
}
