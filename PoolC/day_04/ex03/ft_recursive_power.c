/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/13 10:27:19 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/13 14:01:50 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		powter(int n, int p, int acc)
{
	if (p == 1)
		return (acc * n);
	else if (p % 2)
		return (powter(n * n, p / 2, acc * n));
	else
		return (powter(n * n, p / 2, acc));
}

int		ft_recursive_power(int nb, int power)
{
	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	else
		return (powter(nb, power, 1));
}
