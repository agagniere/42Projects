/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gcd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 18:58:46 by angagnie          #+#    #+#             */
/*   Updated: 2016/10/25 21:37:35 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

int		ft_bezout(int a, int b)
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
	printf("%i * %i + %i * %i = %i\n", a, v[2], b, u[2], r[2]);
	return (r[2]);
}

int		main(int ac, char **av)
{
	if (ac > 2)
		ft_putnbr(ft_bezout(ft_atoi(av[1]), ft_atoi(av[2])));
	ft_putchar('\n');
}
