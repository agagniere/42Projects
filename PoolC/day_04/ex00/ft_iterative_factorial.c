/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/13 09:18:02 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/13 10:03:09 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int		ans;
	int		k;

	if (nb < 0 || nb > 12)
		return (0);
	k = 1;
	ans = 1;
	while (k++ < nb)
		ans *= k;
	return (ans);
}
