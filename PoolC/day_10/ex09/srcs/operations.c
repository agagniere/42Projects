/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/21 20:55:09 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/22 09:43:23 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super.h"

t_string		ft_add(t_myint a, t_myint b)
{
	return (ft_itoa(a + b));
}

t_string		ft_sub(t_myint a, t_myint b)
{
	return (ft_itoa(a - b));
}

t_string		ft_mul(t_myint a, t_myint b)
{
	return (ft_itoa(a * b));
}

t_string		ft_div(t_myint a, t_myint b)
{
	if (b == 0)
		return ("Stop : division by zero");
	return (ft_itoa(a / b));
}
