/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/22 01:58:14 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/22 10:30:08 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super.h"

int			aux(int n, int b, int pos, char *ans)
{
	t_string	c;

	c = "0123456789ABCDEF";
	ans[pos] = (n < b ? c[n] : c[n % b] + aux(n / b, b, pos - 1, ans));
	return (0);
}

t_string	ft_itoa_base(t_myint value, int base)
{
	int			exp;
	t_myint		pow;
	t_string	ans;
	int			is_neg;

	is_neg = (base == 10 && value < 0 ? 1 : 0);
	exp = (is_neg ? 2 : 1);
	value *= (value < 0 ? -1 : 1);
	pow = base;
	while (value >= pow)
	{
		exp++;
		pow *= base;
	}
	if (!(ans = (char *)malloc(exp + 1)))
		return (NULL);
	ans[exp] = '\0';
	if (is_neg)
		*ans = '-';
	aux(value, base, exp - 1, ans);
	return (ans);
}

t_string	ft_itoa(t_myint value)
{
	return (ft_itoa_base(value, 10));
}
