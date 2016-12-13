/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 20:30:10 by angagnie          #+#    #+#             */
/*   Updated: 2016/12/13 19:35:48 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <math.h>

int		pf_rtoa(t_array *d, long double x, int b)
{
	char const *const	base = "0123456789ABCDEF";
	double				frac;
	double				intg;
	int					ans;

	ans = 1 + pf_itoa_base(d, (long long)x, b, 0);
	fta_append(d, ",", 1);
	while ((frac = modf(x, &intg)) != 0.)
	{
		x *= b;
		fta_append(d, (void *)base + ((long long)x % b), 1);
		ans++;
	}
	return (ans);
}

int		pf_cv_f(void)
{
	return (0);
}
