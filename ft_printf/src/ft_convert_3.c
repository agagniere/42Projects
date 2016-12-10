/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 13:55:38 by angagnie          #+#    #+#             */
/*   Updated: 2016/12/08 17:08:15 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** For the d (decimal) and i (integer) conversions
*/

int		pf_cv_di(t_modifier *m, t_dyna *d, va_list ap)
{
	return (pf_signed_integer(m, d, ap, 10));
}

/*
** For the capital X conversion
*/

int		pf_cv_cx(t_modifier *m, t_dyna *d, va_list ap)
{
	if (m->booleans.n.alternate)
	{
		ft_dyna_append(d, "0X", 2);
		m->precision += 2;
		return (2 + pf_unsigned_integer(m, d, ap, -16));
	}
	return (pf_unsigned_integer(m, d, ap, -16));
}

int		pf_cv_x(t_modifier *m, t_dyna *d, va_list ap)
{
	if (m->booleans.n.alternate)
	{
		ft_dyna_append(d, "0x", 2);
		m->precision += 2;
		return (2 + pf_unsigned_integer(m, d, ap, 16));
	}
	return (pf_unsigned_integer(m, d, ap, 16));
}

int		pf_cv_o(t_modifier *m, t_dyna *d, va_list ap)
{
	if (m->booleans.n.alternate)
	{
		ft_dyna_append(d, "0", 1);
		m->precision += 1;
		return (1 + pf_unsigned_integer(m, d, ap, 8));
	}
	return (pf_unsigned_integer(m, d, ap, 16));
}

int		pf_cv_u(t_modifier *m, t_dyna *d, va_list ap)
{
	return (pf_unsigned_integer(m, d, ap, 10));
}
