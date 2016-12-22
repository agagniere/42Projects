/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 13:55:38 by angagnie          #+#    #+#             */
/*   Updated: 2016/12/22 12:54:11 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** For the d (decimal) and i (integer) conversions
*/

int		pf_cv_di(t_modifier *m, t_array *d, va_list ap)
{
	return (pf_signed_integer(m, d, ap, 10));
}

/*
** For the capital X conversion
*/

int		pf_cv_cx(t_modifier *m, t_array *d, va_list ap)
{
	if (m->booleans.n.alternate)
		fta_append(d, "0X", 2);
	return (pf_unsigned_integer(m, d, ap, -16));
}

int		pf_cv_x(t_modifier *m, t_array *d, va_list ap)
{
	if (m->booleans.n.alternate)
		fta_append(d, "0x", 2);
	return (pf_unsigned_integer(m, d, ap, 16));
}

int		pf_cv_o(t_modifier *m, t_array *d, va_list ap)
{
	if (m->booleans.n.alternate)
		fta_append(d, "0", 1);
	return (pf_unsigned_integer(m, d, ap, 8));
}

int		pf_cv_u(t_modifier *m, t_array *d, va_list ap)
{
	return (pf_unsigned_integer(m, d, ap, 10));
}
