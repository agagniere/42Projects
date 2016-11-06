/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 02:02:14 by angagnie          #+#    #+#             */
/*   Updated: 2016/11/06 01:33:49 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline int
	pf_print(t_modifier *m, t_dyna *d, va_list ap)
{
	int		ans;
//	void	*t[] = {pf_cv_di, pf_cv_di, pf_cv_o, pf_cv_u, pf_cv_x, pf_cv_X};

	if ('A' <= m->conversion || m->conversion <= 'Z')
	{
		m->conversion += 32;
		m->length = 'l';
	}
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

	ans = pf_precision(m, d, ap);
	return (ans);
}

void
	pf_convert(t_modifier *m, t_dyna *d, va_list ap)
{
	pf_size(m, d, ap);
}
