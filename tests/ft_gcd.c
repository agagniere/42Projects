/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gcd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 18:58:46 by angagnie          #+#    #+#             */
/*   Updated: 2016/10/25 22:52:31 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_gcd(int a, int b)
{
	int r[3];
	char bool;

	r[2] = a;
	r[1] = b;
	bool = 1;
	while (bool)
	{
		r[0] = r[2] % r[1];
		r[2] = r[1];
		r[1] = r[0];
		bool = (r[0] != 0);
	}
	return (r[2]);
}

int		ft_bezout(int a, int b, int *o)
{
	int		r[3];
	int		u[3];
	int		v[3];
	int		q;
	char	bool;

	r[2] = a;
	r[1] = b;
	u[2] = 0;
	u[1] = 1;
	v[2] = 1;
	v[1] = 0;
	bool = 1;
	while (bool)
	{
		// s = r u v
		// s[n+1] = s[n-1] - q * s[n]
		q = r[2] / r[1];
		r[0] = r[2] % r[1];
		u[0] = u[2] - q * u[1];
		v[0] = v[2] - q * v[1];
		// n++
		r[2] = r[1];
		r[1] = r[0];
		u[2] = u[1];
		u[1] = u[0];
		v[2] = v[1];
		v[1] = v[0];
		bool = (r[0] != 0);
	}
	o[0] = v[2];
	o[1] = u[2];
	printf("%i.%i + %i.%i = %i\n", o[0], a, o[1], b, r[2]);
	return (r[2]);
}

int		ft_diophantine(int a, int b, int c, int *o)
{
	int		p;
	int		d[2];

	p = ft_bezout(a, b, d);
	if (p == 1)
	{
		o[0] = c * d[0];
		o[1] = c * d[1];
		o[2] = b;
		o[3] = a;
	}
	else
	{
		if (c % p == 0)
			ft_diophantine(a / p, b / p, c / p, o);
		else
			return (1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	int a, b, c;
	int	d[4];

	if (ac > 2)
	{
		a = ft_atoi(av[1]);
		b = ft_atoi(av[2]);
		if (ac > 3)
			c = ft_atoi(av[3]);
		else
			c = 1;
		printf("Solve :\t%ix + %iy = %i\n", a, b, c);
		if (!ft_diophantine(a, b, c, d))
		{
			printf("{ x = %i - %i.k\n", d[0], d[2]);
			printf("{ y = %i + %i.k\n", d[1], d[3]);
		}
		else
			ft_putstr("No solutions\n");
	}
	return (0);
}
