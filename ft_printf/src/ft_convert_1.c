/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:37:36 by angagnie          #+#    #+#             */
/*   Updated: 2016/11/27 23:49:27 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define MIN(A,B) (A < B ? A : B)

int		pf_itoa_base(t_dyna *d, long int n, int b)
{
	const char	*base = "0123456789ABCDEF";
	int			ans;

	ans = 1;
	if (n <= -b || b <= n)
		ans += pf_itoa_base(d, n / b, b);
	ft_dyna_append(d, (void *)(base + ABS(n % b)), 1);
	return (ans);
}

int		pf_cv_di(t_modifier *m, t_dyna *d, va_list ap)
{
	long int	arg;
	int			ans;

	arg = va_arg(ap, long int);
	ans = 0;
	if (arg < 0 && ++ans)
		ft_dyna_append(d, "-", 1);
	ans += ft_itoa_base(d, arg, 10);
	if (arg == 0 && m->precision == 0 && ++ans)
		ft_dyna_append(d, "0", 1);
	return (ans);
}

int		pf_cv_X(t_modifier *m, t_dyna *d, va_list ap)
{
	long int	arg;
	int			ans;

	arg = va_arg(ap, long int);
	ans = 0;
	if (m->booleans.n.alternate && (ans += 2) >= 0)
		ft_dyna_append(d, "0X", 2);
	ans += pf_itoa_base(d, arg, 10);
	if (arg == 0 && m->precision == 0 && ++ans)
		ft_dyna_append(d, "0", 1);
	return (ans);
}

int		pf_cv_s(t_modifier *m, t_dyna *d, va_list ap)
{
	char	*arg;
	int		ans;

	arg = va_arg(ap, char *);
	ans = (m->precision != 0 ? MIN(ft_strlen(arg),
		(size_t)m->precision) : ft_strlen(arg));
	ft_dyna_append(d, (void *)arg, ans);
	return (ans);
}

int		pf_cv_S(t_modifier *m, t_dyna *d, va_list ap)
{
	wchar_t	*arg;
	int		ans;

	arg = va_arg(ap, wchar_t *);
	ans = (m->precision != 0 ? MIN(wc_strlen(arg),
		(size_t)m->precision) : wc_strlen(arg));
	ft_dyna_append(d, (void *)arg, 2 * ans);
	return (ans);
}
