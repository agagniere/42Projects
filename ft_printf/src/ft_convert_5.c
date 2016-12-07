/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 11:41:29 by angagnie          #+#    #+#             */
/*   Updated: 2016/12/07 22:52:52 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_cv_b(t_modifier *m, t_dyna *d, va_list ap)
{
	if (m->booleans.n.alternate)
	{
		ft_dyna_append(d, "b", 1);
		return (1 + pf_unsigned_integer(m, d, ap, 2));
	}
	return (pf_unsigned_integer(m, d, ap, 2));
}

int		pf_cv_p(t_modifier *m, t_dyna *d, va_list ap)
{
	void	*arg;

	arg = va_arg(ap, void *);
	ft_dyna_append(d, "0x", 2);
	pf_itoa_base(d, (long long)arg, 16, 2);
	return (0);
}
