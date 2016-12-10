/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 02:02:14 by angagnie          #+#    #+#             */
/*   Updated: 2016/12/08 17:07:37 by angagnie         ###   ########.fr       */
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

void
	tmp_dyna_swap(t_dyna *d, size_t before, size_t after)
{
	char			*tmp;
	const size_t	len = after - before;
	const size_t	m = d->chunck_size;

	tmp = ft_safe_calloc(len, m);
	ft_memcpy(tmp, d->data + before * m, m * len);
	ft_memmove(d->data + before * m, d->data + after * m,
		(d->chunck_count - after) * m);
	ft_memcpy(d->data + (d->chunck_count - len) * m, tmp, len * m);
}

static inline int
	pf_precision(t_modifier *m, t_dyna *d, va_list ap)
{
	int		ans;
	size_t	before;
	size_t	after;

	before = d->chunck_count;
	ans = pf_print(m, d, ap);
	after = d->chunck_count;
	if (ans < m->precision && is_in(m->conversion, "diouDOUxX") >= 0)
	{
		while (ans < m->precision && ++ans)
			ft_dyna_append(d, "0", 1);
		tmp_dyna_swap(d, before, after);
	}
	return (ans);
}

static inline int
	pf_size(t_modifier *m, t_dyna *d, va_list ap)
{
	int		ans;
	size_t	before;
	size_t	after;

	before = d->chunck_count;
	ans = pf_precision(m, d, ap);
	after = d->chunck_count;
	if (ans < m->size)
	{
		if (m->booleans.n.zero && m->precision == -1
			&& !m->booleans.n.minus
			)
			while (ans < m->size && ++ans)
				ft_dyna_append(d, "0", 1);
		else
			while (ans < m->size && ++ans)
				ft_dyna_append(d, " ", 1);
		if (!m->booleans.n.minus)
			tmp_dyna_swap(d, before, after);
	}
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
