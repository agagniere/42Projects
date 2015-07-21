/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/21 20:55:09 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/21 21:39:25 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super.h"

t_myint		plus(t_myint a, t_myint b)
{
	return (a + b);
}

t_myint		minus(t_myint a, t_myint b)
{
	return (a - b);
}

t_myint		times(t_myint a, t_myint b)
{
	return (a * b);
}

t_myint		divide(t_myint a, t_myint b)
{
	if (b == 0)
		return (ERROR);
	return (a / b);
}

t_myint		modulo(t_myint a, t_myint b)
{
	if (b == 0)
		return (ERROR);
	return (a % b);
}
