/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/13 11:07:16 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/13 14:02:18 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** index should be smaller than 46
*/

int		fibter(int n, int a, int b)
{
	if (n == 1)
		return (b);
	else
		return (fibter(n - 1, b, a + b));
}

int		ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	else if (index == 0)
		return (0);
	else
		return (fibter(index, 0, 1));
}
