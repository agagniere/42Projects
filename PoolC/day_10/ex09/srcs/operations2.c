/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/21 20:55:09 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/22 09:58:34 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super.h"

t_string		ft_mod(t_myint a, t_myint b)
{
	if (b == 0)
		return ("Stop : modulo by zero");
	return (ft_itoa(a % b));
}

t_myint			aux_pow(t_myint n, t_myint p, t_myint acc)
{
	if (p == 0)
		return (acc);
	if (p == 1)
		return (n * acc);
	if (p % 2)
		return (aux_pow(n * n, p / 2, acc * n));
	return (aux_pow(n * n, p / 2, acc));
}

t_string		ft_pow(t_myint a, t_myint b)
{
	return (ft_itoa(aux_pow(a, b, 1)));
}

t_string		ft_usage(t_myint a, t_myint b)
{
	(void)a;
	(void)b;
	return ("error : only [ - + * / % ^ ] are accepted.");
}
