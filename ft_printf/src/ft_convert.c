/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 02:02:14 by angagnie          #+#    #+#             */
/*   Updated: 2016/12/24 01:40:35 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline int
	pf_print(t_modifier *m, t_array *d, va_list ap)
{
	int			i;
	char const	*c = "diouxXcCsSpbn";
	void *const	t[] = {&pf_cv_di, &pf_cv_di, &pf_cv_o, &pf_cv_u, &pf_cv_x,
			&pf_cv_cx, &pf_cv_c, &pf_cv_wc, &pf_cv_s, &pf_cv_ws,
			&pf_cv_p, &pf_cv_b, &pf_cv_n};

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
		return (((int (*)())t[i])(m, d, ap));
	if (m->conversion)
		fta_append(d, &m->conversion, 1);
	return (1);
}

void
	tmp_dyna_swap(t_array *d, size_t before, size_t after)
{
	char			*tmp;
	const size_t	len = after - before;
	const size_t	m = d->type_size;

	tmp = ft_safe_calloc(len, m);
	ft_memcpy(tmp, d->data + before * m, m * len);
	ft_memmove(d->data + before * m, d->data + after * m,
		(d->size - after) * m);
	ft_memcpy(d->data + (d->size - len) * m, tmp, len * m);
	free(tmp);
}

static inline int
	pf_precision(t_modifier *m, t_array *d, va_list ap)
{
	size_t	before;
	size_t	after;
	int		width;
	int		len;

	before = d->size;
	width = pf_print(m, d, ap);
	after = d->size;
	len = width;
	if (len < m->precision && is_in(m->conversion, FTPF_NUMERIC) >= 0)
	{
		while (len < m->precision && ++len)
			fta_append(d, "0", 1);
		tmp_dyna_swap(d, after - width, after);
	}
	return (len);
}

void
	pf_convert(t_modifier *m, t_array *d, va_list ap)
{
	size_t	before;
	size_t	after;
	int		width;
	int		len;

	before = d->size;
	width = pf_precision(m, d, ap);
	after = d->size;
	len = after - before;
	if (len < m->size)
	{
		if (m->booleans.n.zero
			&& m->precision == -1
			&& !m->booleans.n.minus)
		{
			while (len < m->size && ++len)
				fta_append(d, "0", 1);
			before = after - width;
		}
		else
			while (len < m->size && ++len)
				fta_append(d, " ", 1);
		if (!m->booleans.n.minus)
			tmp_dyna_swap(d, before, after);
	}
}
