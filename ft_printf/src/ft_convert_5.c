/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 11:41:29 by angagnie          #+#    #+#             */
/*   Updated: 2017/09/22 21:56:47 by angagnie         ###   ########.fr       */
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
	fta_append(d, "0x", 2);
	m->length = 'L';
	return (pf_unsigned_integer(m, d, ap, 16));
}

int		pf_cv_n(t_modifier *m, t_array *d, va_list ap)
{
	int		*arg;

	arg = va_arg(ap, void *);
	m->size = 0;
	m->precision = -1;
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
	else
		*(int *)arg = (int)d->size;
	return (0);
}
