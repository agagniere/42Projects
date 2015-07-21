/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/13 10:23:42 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/13 12:40:03 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int ans;

	if (power < 0)
		return (0);
	ans = 1;
	while (power-- > 0)
		ans *= nb;
	return (ans);
}
