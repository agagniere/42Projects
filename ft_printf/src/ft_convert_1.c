/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:37:36 by angagnie          #+#    #+#             */
/*   Updated: 2016/11/30 21:24:26 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pf_itoa_base(t_dyna *d, long long n, int b, int shift)
{
	const char		*base = (shift ? "0123456789ABCDEF" : "0123456789abcdef");
	int				ans;

	ans = 1;
	if (n <= -b || b <= n)
		ans += pf_itoa_base(d, n / b, b, shift);
	ft_dyna_append(d, (void *)(base + ABS(n % b)), 1);
	return (ans);
}

int			pf_signed_integer(t_modifier *m, t_dyna *d, va_list ap, int b)
{
	long long	arg;

	if (m->length == 'H')
		arg = (signed char)va_arg(ap, int);
	else if (m->length == 'h')
		arg = (short)va_arg(ap, int);
	else if (m->length == 'l')
		arg = va_arg(ap, long);
	else if (m->length == 'L')
		arg = va_arg(ap, long long);
	else
		arg = va_arg(ap, int);
	if (b == 10 && arg < 0)
	{
		ft_dyna_append(d, "-", 1);
		return (1 + pf_itoa_base(d, arg, ABS(b), b < 0));
	}
	return (pf_itoa_base(d, arg, ABS(b), b < 0));
}

int			pf_cv_di(t_modifier *m, t_dyna *d, va_list ap)
{
	return (pf_signed_integer(m, d, ap, 10));
}

int			pf_cv_cx(t_modifier *m, t_dyna *d, va_list ap)
{
	if (m->booleans.n.alternate)
	{
		ft_dyna_append(d, "0X", 2);
		return (2 + pf_signed_integer(m, d, ap, -16));
	}
	return (pf_signed_integer(m, d, ap, -16));
}

int			pf_cv_x(t_modifier *m, t_dyna *d, va_list ap)
{
	if (m->booleans.n.alternate)
	{
		ft_dyna_append(d, "0x", 2);
		return (2 + pf_signed_integer(m, d, ap, 16));
	}
	return (pf_signed_integer(m, d, ap, 16));
}

int			pf_cv_o(t_modifier *m, t_dyna *d, va_list ap)
{
	if (m->booleans.n.alternate)
	{
		ft_dyna_append(d, "0", 1);
		return (1 + pf_signed_integer(m, d, ap, 8));
	}
	return (pf_signed_integer(m, d, ap, 16));
}

int			pf_cv_u(t_modifier *m, t_dyna *d, va_list ap)
{
	long long unsigned	arg;
	int					ans;

	if (m->length == 'H')
		arg = (unsigned char)va_arg(ap, unsigned);
	else if (m->length == 'h')
		arg = (unsigned short)va_arg(ap, unsigned);
	else if (m->length == 'l')
		arg = va_arg(ap, unsigned long);
	else if (m->length == 'L')
		arg = va_arg(ap, unsigned long long);
	else
		arg = va_arg();
	ans = 0;
	if (m->booleans.n.alternate && (ans += 2) >= 0)
		ft_dyna_append(d, "0", 2);
	ans += pf_itoa_base(d, arg, 10, 0);
	return (ans);
}
