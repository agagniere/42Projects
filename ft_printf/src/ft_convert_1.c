/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:37:36 by angagnie          #+#    #+#             */
/*   Updated: 2016/12/04 20:26:17 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			pf_itoa_base(t_dyna *d, long long n, int b, char info)
{
	int							ans;
	const unsigned long long	un = (unsigned long long)n;
	const char *const			base =

	(info & 1 ? "0123456789ABCDEF" : "0123456789abcdef");
	ans = 1;
	if (b <= (info & 2 ? un : n) || (!(info & 2) && n <= -b))
		ans += pf_itoa_base(d, (info & 2 ? un : n) / b, b, info);
	ft_dyna_append(d, (void *)(base + ABS((info & 2 ? un : n) % b)), 1);
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
	if (arg < 0)
	{
		ft_dyna_append(d, "-", 1);
		return (1 + pf_itoa_base(d, arg, ABS(b), b < 0));
	}
	return (pf_itoa_base(d, arg, ABS(b), b < 0));
}

int			pf_unsigned_integer(t_modifier *m, t_dyna *d, va_list ap, int b)
{
	long long unsigned	arg;

	if (m->length == 'H')
		arg = (unsigned char)va_arg(ap, unsigned);
	else if (m->length == 'h')
		arg = (unsigned short)va_arg(ap, unsigned);
	else if (m->length == 'l')
		arg = va_arg(ap, unsigned long);
	else if (m->length == 'L')
		arg = va_arg(ap, unsigned long long);
	else
		arg = va_arg(ap, unsigned);
	return (pf_itoa_base(d, arg, ABS(b), 2 | (b < 0)));
}
