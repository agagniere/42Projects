/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 02:02:14 by angagnie          #+#    #+#             */
/*   Updated: 2016/12/07 23:42:57 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline int
	pf_print(t_modifier *m, t_dyna *d, va_list ap)
{
	int			ans;
	int			i;
	char const	*c = "diouxXcCsSpbn";
	void *const	t[] = {&pf_cv_di, &pf_cv_di, &pf_cv_o, &pf_cv_u, &pf_cv_x,
					   &pf_cv_cx, &pf_cv_c, &pf_cv_wc, &pf_cv_s, &pf_cv_ws,
					   &pf_cv_p, &pf_cv_b, &pf_cv_n};

	ans = 0;
	if (m->length == 'l' && is_in(m->conversion, "cs") >= 0)
		m->conversion -= 32;
	if (is_in(m->conversion, "DOU") >= 0)
	{
		m->conversion += 32;
		m->length = 'l';
	}
	i = 0;
	while (c[i] != '\0' && m->conversion != c[i])
		i++;
	if (c[i] != '\0')
		ans += ((int (*)())t[i])(m, d, ap);
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
	if (m->booleans.n.zero && m->precision == -1
		&& is_in(m->conversion, "diuoxX") >= 0)
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
