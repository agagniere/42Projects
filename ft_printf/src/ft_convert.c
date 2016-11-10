/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 02:02:14 by angagnie          #+#    #+#             */
/*   Updated: 2016/11/10 17:53:47 by angagnie         ###   ########.fr       */
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
	while (ans < m->precision && ++ans)
		ft_dyna_append(d, "0", 1);
	return (ans);
}

static inline int
	pf_size(t_modifier *m, t_dyna *d, va_list ap)
{
	int		ans;
	char	*s;

	s = (char *)d->data;
	ans = pf_precision(m, d, ap);
	if (m->precision == 0 && 0 <= is_in(m->conversion, "diuoxX"))
		while (ans < m->size && ++ans)
			ft_dyna_append(d, "0", 1);
	while (ans < m->size && ++ans)
		ft_dyna_append(d, " ", 1);
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
