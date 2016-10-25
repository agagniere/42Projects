/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gcd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 18:58:46 by angagnie          #+#    #+#             */
/*   Updated: 2016/10/25 22:10:13 by angagnie         ###   ########.fr       */
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
	//printf("%i * %i + %i * %i = %i\n", a, v[2], b, u[2], r[2]);
	o[0] = v[2];
	o[1] = u[2];
	return (r[2]);
}

int		ft_diophantine(int a, int b, int c)
{
	int		p;
	int		d[2];

	printf("Solve %ix + %ib = %i\n", a, b, c);
	p = ft_bezout(a, b, d);
	if (p == 1)
	{
		printf("x = %i - %ik\n", c * d[0], b);
		printf("y = %i - %ik\n", c * d[1], a);
	}
	else
	{
		if (c % p == 0)
		{
			printf("Multiply by %i the solutions of :\n", p);
			ft_diophantine(a / p, b / p, c / p);
		}
		else
			ft_putstr("No solution\n");
	}
	return (0);
}

int		main(int ac, char **av)
{
	if (ac > 3)
		ft_diophantine(ft_atoi(av[1]), ft_atoi(av[2]), ft_atoi(av[3]));
	ft_putchar('\n');
	return (0);
}
