/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/13 09:20:17 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/13 14:00:57 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		facter(int n, int acc)
{
	if (n < 2)
		return (acc);
	else
		return (facter(n - 1, acc * n));
}

int		ft_recursive_factorial(int nb)
{
	if (nb < 0 || nb > 12)
		return (0);
	else
		return (facter(nb, 1));
}
