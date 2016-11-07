/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 02:02:14 by angagnie          #+#    #+#             */
/*   Updated: 2016/11/07 21:14:50 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline int
	pf_print(t_modifier *m, t_dyna *d, va_list ap)
{
	int		ans = 0;
//	void	*t[] = {pf_cv_di, pf_cv_di, pf_cv_o, pf_cv_u, pf_cv_x, pf_cv_X};

	if (m->conversion == 's')
		ans = pf_cv_sS(m, d, ap);
	if (m->conversion == 'i')
		ans = pf_cv_di(m, d, ap);
	return (ans);
}

static inline int
	pf_precision(t_modifier *m, t_dyna *d, va_list ap)
{
	int		ans;

	ans = pf_print(m, d, ap);
	return (ans);
}

static inline int
	pf_size(t_modifier *m, t_dyna *d, va_list ap)
{
	int		ans;
	char	*s;

	s = (char *)d->data;
	ans = pf_precision(m, d, ap);
//	while (m->size >)
	return (ans);
}

void
	pf_convert(t_modifier *m, t_dyna *d, va_list ap)
{
	if (m->conversion == '%')
		ft_dyna_append(d, "%", 1);
	else
		pf_size(m, d, ap);
}
