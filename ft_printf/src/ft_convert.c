/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 02:02:14 by angagnie          #+#    #+#             */
/*   Updated: 2016/11/30 15:07:01 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline int
	pf_print(t_modifier *m, t_dyna *d, va_list ap)
{
	int		ans;
//	void	*t[] = {pf_cv_di, pf_cv_di, pf_cv_o, pf_cv_u, pf_cv_x, pf_cv_X};

	ans = 0;
	if (m->length == 'l')
	{
		if (m->conversion == 's')
			ans = pf_cv_ws(m, d, ap);
		else if (m->conversion == 'c')
			ans = pf_cv_wc(m, d, ap);
	}
	else if (m->conversion == 'S')
		ans = pf_cv_ws(m, d, ap);
	else if (m->conversion == 's')
		ans = pf_cv_s(m, d, ap);
	else if (m->conversion == 'C')
		ans = pf_cv_wc(m, d, ap);
	else if (m->conversion == 'c')
		ans = pf_cv_c(m, d, ap);
	else if (m->conversion == 'i')
		ans = pf_cv_di(m, d, ap);
	else if (m->conversion == 'x')
		ans = pf_cv_x(m, d, ap);
	else if (m->conversion == 'X')
		ans = pf_cv_cx(m, d, ap);
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

	ans = pf_precision(m, d, ap);
	if (m->booleans.n.zero && m->precision == 0
		&& 0 <= is_in(m->conversion, "diuoxX"))
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
