/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/13 13:44:22 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/14 15:41:34 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		dich_sqrt(int n, int lower, int upper)
{
	long long int mid;
	long long int mid_sq;

	mid = (lower + upper) / 2;
	mid_sq = mid * mid;
	if (mid == lower)
		return (0);
	else if (mid_sq == n)
		return (mid);
	else if (mid_sq < n)
		return (dich_sqrt(n, mid, upper));
	else
		return (dich_sqrt(n, lower, mid));
}

int		ft_sqrt(int nb)
{
	if (nb > 1)
		return (dich_sqrt(nb, 0, nb));
	else if (nb == 1)
		return (1);
	else
		return (0);
}
