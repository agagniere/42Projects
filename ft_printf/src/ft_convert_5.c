/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 11:41:29 by angagnie          #+#    #+#             */
/*   Updated: 2016/12/22 10:13:19 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_cv_b(t_modifier *m, t_array *d, va_list ap)
{
	if (m->booleans.n.alternate)
		fta_append(d, "b", 1);
	return (pf_unsigned_integer(m, d, ap, 2));
}

int		pf_cv_p(t_modifier *m, t_array *d, va_list ap)
{
	void	*arg;

	(void)m;
	arg = va_arg(ap, void *);
	fta_append(d, "0x", 2);
	return (pf_itoa_base(d, (long long)arg, 16, 2));
}

int		pf_cv_n(t_modifier *m, t_array *d, va_list ap)
{
	int		*arg;

	arg = va_arg(ap, int *);
	if (m->length == 'H')
		*(char *)arg = (char)d->size;
	else if (m->length == 'h')
		*(short *)arg = (short)d->size;
	else if (m->length == 'l' || m->length == 'z')
		*(long *)arg = (long)d->size;
	else if (m->length == 'L')
		*(long long *)arg = (long long)d->size;
	else if (m->length == 'j')
		*(intmax_t *)arg = (intmax_t)d->size;
	return (0);
}
