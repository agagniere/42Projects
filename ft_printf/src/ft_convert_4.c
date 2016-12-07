/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 20:30:10 by angagnie          #+#    #+#             */
/*   Updated: 2016/12/07 22:51:02 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_rtoa(t_dyna *d, long double x, int b)
{
	char const *const	base = "0123456789ABCDEF";
	double				frac;
	double				intg;
	int					ans;

	ans = pf_itoa_base(d, (long long)x, b, 0);
	ft_dyna_append(d, ",", 1);
	while ((frac = modf(x, &intg)) != 0.)
	{
		x *= b;
		ft_dyna_append(d, base + ((long long)x % b), 1);
		ans++;
	}
	return (2 +);
}

int		pf_cv_f()
{
	return (0);
}
