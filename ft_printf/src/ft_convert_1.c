/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:37:36 by angagnie          #+#    #+#             */
/*   Updated: 2016/11/30 12:39:13 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define MIN(A,B) (A < B ? A : B)

static int	pf_itoa_base(t_dyna *d, long int n, int b)
{
	const char		*base = "0123456789ABCDEF";
	int				ans;

	ans = 1;
	if (n <= -b || b <= n)
		ans += pf_itoa_base(d, n / b, b);
	ft_dyna_append(d, (void *)(base + ABS(n % b)), 1);
	return (ans);
}

int			pf_cv_di(t_modifier *m, t_dyna *d, va_list ap)
{
	long int	arg;
	int			ans;

	arg = va_arg(ap, long int);
	ans = 0;
	if (arg < 0 && ++ans)
		ft_dyna_append(d, "-", 1);
	ans += pf_itoa_base(d, arg, 10);
	if (arg == 0 && m->precision == 0 && ++ans)
		ft_dyna_append(d, "0", 1);
	return (ans);
}

int			pf_cv_X(t_modifier *m, t_dyna *d, va_list ap)
{
	long int	arg;
	int			ans;

	arg = va_arg(ap, long int);
	ans = 0;
	if (m->booleans.n.alternate && (ans += 2) >= 0)
		ft_dyna_append(d, "0X", 2);
	ans += pf_itoa_base(d, arg, 16);
	if (arg == 0 && m->precision == 0 && ++ans)
		ft_dyna_append(d, "0", 1);
	return (ans);
}

int			pf_cv_x(t_modifier *m, t_dyna *d, va_list ap)
{
	long int	arg;
	int			ans;

	arg = va_arg(ap, long int);
	ans = 0;
	if (m->booleans.n.alternate && (ans += 2) >= 0)
		ft_dyna_append(d, "0x", 2);
	ans += pf_itoa_base(d, arg, 16);
	if (arg == 0 && m->precision != 0 && ++ans)
		ft_dyna_append(d, "0", 1);
	return (ans);
}
