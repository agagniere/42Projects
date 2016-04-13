/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 11:24:31 by angagnie          #+#    #+#             */
/*   Updated: 2016/04/13 13:35:27 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** EFFETS DE BORD
*/
void	ft_mat2x2_pow(t_mat2x2 *m, size_t p)
{
	t_mat2x2	s;

	if (p == 0)
	{
		m->data[0] = 1;
		m->data[1] = 0;
		m->data[2] = 0;
		m->data[3] = 1;
	}
	else if (p > 1 && p % 2)
	{
		s = *m;
		ft_mat2x2_pow(m, p - 1);
		ft_mat2x2_mult_mat2x2(m, s);
	}
}

/*
** This function has a O(log_2(n)) complexity,
** and is to be prefered when n > 30
*/

size_t	ft_fib2(unsigned char n)
{
	t_vect2		f;
	t_mat2x2	m;

	if (n > 93)
		return (0);
	f.x = 1;
	f.y = 0;
	m.data[0] = 1;
	m.data[1] = 1;
	m.data[2] = 1;
	m.data[3] = 0;
	ft_mat2x2_pow(&m, n);
}


/*
** This function has a O(n) complexity
** and can be used when n < 48
*/
unsigned int	ft_fib(unsigned char n)
{
	unsigned int	fn;
	unsigned int	fnm1;
	unsigned int	fnm2;

	if (n > 47)
		return (0);
	else if (n == 0)
		return (0);
	fn = 1;
	fnm1 = 0;
	while (n-- > 1)
	{
		fnm2 = fnm1;
		fnm1 = fn;
		fn = fnm1 + fnm2;
	}
	return (fn);
}

/*
** This function does not handle overflow !
*/
unsigned int	ft_fibg(unsigned char n, unsigned char u0, unsigned char u1)
{
	unsigned int	un;

	un = u0;
	while (n-- > 0)
	{
		u0 = u1;
		u1 += un;
		un = u0;
	}
	return (un);
}
