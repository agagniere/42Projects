/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:37:36 by angagnie          #+#    #+#             */
/*   Updated: 2016/11/07 19:08:39 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

# define MIN(A,B) (A < B ? A : B)

int		pf_cv_di(t_modifier *m, t_dyna *d, va_list ap)
{
	int		arg;
	int		n;
	int		ans;
	char	*base = "0123456789";

	arg = va_arg(ap, int);
	n = arg;
	ans = 0;
	while (n != 0 && ++ans)
	{
		ft_dyna_append(d, (void *)base + ABS(n % 10), 1);
		n /= 10;
	}
	if (arg < 0 && ++ans)
		ft_dyna_append(d, "-", 1);
	else if (arg == 0 && m->precision == 0 && ++ans)
		ft_dyna_append(d, "0", 1);
	return (ans);
}

int		pf_cv_sS(t_modifier *m, t_dyna *d, va_list ap)
{
	char	*arg;
	int		ans;

	arg = va_arg(ap, char *);
	ans = (m->precision == 0 ? MIN(ft_strlen(arg),
		(unsigned)m->precision) : m->precision);
	ft_dyna_append(d, (void *)arg, ans-- + 1);
	return (ans);
}
