/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 17:04:01 by angagnie          #+#    #+#             */
/*   Updated: 2016/11/01 08:52:01 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "ft_printf.h"

void	pf_convert(t_modifier *m, va_list *ap, t_dyna *d)
{
	db_print_modifier(m);
//	if (m->plus)
/* 	int		n; */
/* 	void	*f[] = {pfcv_di, pfcv_di}; */

/* 	n = is_in(m->conversion, FTPF_CV); */
/* 	((void (*)())f[n])(m, ap, d); */
}

void	pf_update_value(char const **s, int *v)
{
	*v = 0;
	while ('0' <= **s && **s <= '9')
		*v = 10 * (*v) + *(*s)++ - '0';
}

int		pf_match(char const **s, t_modifier *m)
{
	int			n;
	char const	c = **s;

	if ((n = is_in(c, "0+- #")) >= 0)
		m->booleans.t[n] = 1;
	else if ((n = is_in(c, FTPF_CV)) >= 0)
	{
		m->conversion = c;
		return (1);
	}
	else if (c == '.' && *++*s)
		pf_update_value(s, &(m->precision));
	else if ('1' <= c && c <= '9')
		pf_update_value(s, &(m->size));
	return (0);
}

void	pf_parse(char const *s, va_list *ap)
{
	t_dyna		d;
	t_modifier	m;
	char		*p;

	d = ft_dyna_new(sizeof(char));
	m = NEW_MODIFIER;
	while (*s != '\0')
	{
		p = s;
		while (*p != '\0' && *p != '%')
			p++;
		ft_dyna_append(&d, s, p - s);
		s = p;
	}
	ft_dyna_append(&d, "\0", 1);
	write(1, d.data, d.chunck_count);
}

int		ft_printf(char const *format, ...)
{
	va_list		ap;

	va_start(ap, format);
	pf_parse(format, &ap);
	va_end(ap);
	return (0);
}

int		main(int ac, char **av)
{
	char		*s = "(%0+- #u,%i)\n";

	(void)ac;
	(void)av;
	printf(s, -2147000123, 2, 3);
	ft_printf(s, -2147000123, 2, 3);
	return (0);
}
