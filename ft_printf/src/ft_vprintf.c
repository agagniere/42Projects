/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 17:04:01 by angagnie          #+#    #+#             */
/*   Updated: 2016/11/01 19:24:22 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "ft_printf.h"

void
	pf_convert(t_modifier *m, t_dyna *d, va_list *ap)
{
	db_print_modifier(m); // <==
	if (m->conversion == 0)
		return ;
	else if (m->conversion == '%')
		ft_dyna_append(d, "%", 1);
	else

}

const char
	*pf_update_value(char const *s, int *v)
{
	*v = 0;
	while ('0' <= *s && *s <= '9')
		*v = 10 * (*v) + *s++ - '0';
	return (s);
}

void
	pf_set_length(char c, char *lm)
{
	if ((c == 'h' || c == 'l') && *lm == c)
		*lm = c - 32;
	else if (*lm == 0 || !(c == 'h' && *lm != 'H'))
		*lm = c;
}

const char
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
		else if ((n = is_in(*s, FTPF_LM)) >= 0)
			pf_set_length(*s, &(m->length));
		else if (is_in(*s, FTPF_CV) >= 0 && (m->conversion = *s))
			return (s + 1);
		else
		{ // <--
			printf("/!\\ STOP : %c\n", *s); // <==
			break ;
		} // <--
		s++;
	}
	return (s);
}

char
	*ft_vprintf(char const *s, va_list ap)
{
	t_dyna		d;
	t_modifier	m;
	char const	*p;

	d = ft_dyna_new(sizeof(char));
	while (*s != '\0')
	{
		m = NEW_MODIFIER;
		if (*s == '%')
		{
			s = pf_match(s + 1, &m);
			pf_convert(&m, &d, &ap);
		}
		p = s;
		while (*p != '\0' && *p != '%')
			p++;
		ft_dyna_append(&d, s, p - s);
		s = p;
	}
	ft_dyna_append(&d, "\0", 1);
	return ((char *)d.data);
}
