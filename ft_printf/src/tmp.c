/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alignment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 14:32:52 by malaine           #+#    #+#             */
/*   Updated: 2016/11/02 18:41:01 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putnbr_rev(t_dyna *d, int a)
{
	int		count;
	char	c;

	count = 0;
	while (a != 0)
	{
		c = (a % 10) + '0';
		ft_dyna_append(d, &c, 1);
		count++;
		a /= 10;
	}
	return(count);
}

int		ft_precision(int a, t_modifier *m)
{
	int z;

	z = ft_putnbr_rev(a);
	while (z < m->precision)
	{
		write(1, "0", 1);
		z++;
	}
	return (z);
}

int		ft_size(int a, t_modifier *m)
{
	int z;

	z = ft_precision(a, m);
	if (m->precision > 0 || m->booleans.n.zero == 0 || m->booleans.n.minus)
	{
		if (m->booleans.n.plus)
		{
			write(1, "+", 1);
			z++;
		}
		if (m->booleans.n.minus)
			ft_rev(s);
		while (z < m->size)
		{
			write(1, " ", 1);
			z++;
		}
	}
	else if (m->booleans.n.zero)
	{
		while (z < m->size)
		{
			write(1, "0", 1);
			z++;
		}
		if (m->booleans.n.plus)
			write(1, "\\+", 2);
		else if (m->booleans.n.space)
			write(1, "\\ ", 2);
	}
	return (z);
}

int main(void)
{
	ft_size(422, &NEW_MODIFIER);
	return (0);
}
