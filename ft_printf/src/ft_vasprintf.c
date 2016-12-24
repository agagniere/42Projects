/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 17:04:01 by angagnie          #+#    #+#             */
/*   Updated: 2016/12/24 01:37:15 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline const char
	*pf_update_value(char const *s, int *v)
{
	*v = 0;
	while ('0' <= *s && *s <= '9')
		*v = 10 * (*v) + *s++ - '0';
	return (s);
}

static inline void
	pf_set_length(char c, char *lm)
{
	if ((c == 'h' || c == 'l') && *lm == c)
		*lm = c - 32;
	else if (*lm == 0 || !(c == 'h' && *lm != 'H'))
		*lm = c;
}

static inline const char
	*pf_match(char const *s, t_modifier *m)
{
	int			n;

	while (*s != '\0')
	{
		if (*s == '.')
			s = pf_update_value(s + 1, &(m->precision)) - 1;
		else if ('1' <= *s && *s <= '9')
			s = pf_update_value(s, &(m->size)) - 1;
		else if ((n = is_in(*s, "0+- #")) >= 0)
			m->booleans.t[n] = 1;
		else if (is_in(*s, FTPF_LM) >= 0)
			pf_set_length(*s, &(m->length));
		else if ((m->conversion = *s))
			return (s + 1);
		s++;
	}
	return (s);
}

int
	ft_vasprintf(char **ret, char const *s, va_list ap)
{
	t_array		d;
	t_modifier	m;
	char const	*p;

	d = NEW_ARRAY(char);
	fta_reserve(&d, ft_strlen(s));
	while (*s != '\0')
	{
		m = NEW_MODIFIER;
		if (*s == '%')
		{
			s = pf_match(s + 1, &m);
			pf_convert(&m, &d, ap);
		}
		p = s;
		while (*p != '\0' && *p != '%')
			p++;
		if (p != s)
			fta_append(&d, (void *)s, p - s);
		s = p;
	}
	fta_append(&d, "\0", 1);
	fta_trim(&d);
	*ret = d.data;
	return (d.size - 1);
}

/*
** -------------------
**		m = NEW_MODIFIER;
**		p = s;
**		while (*p != '\0' && *p != '%')
**			p++;
**		if (p != s)
**			fta_append(&d, (void *)s, p - s);
**		s = p;
**		if (*p == '%')
**		{
**			s = pf_match(p + 1, &m);
**			pf_convert(m, d, ap);
**		}
** ===============
*/
