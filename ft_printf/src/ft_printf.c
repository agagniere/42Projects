/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 17:04:01 by angagnie          #+#    #+#             */
/*   Updated: 2016/10/31 09:17:35 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

#include "libft.h"

typedef	struct	s_modifier
{
	union
	{
		char	t[6];
		struct
		{
			char	zero;
			char	plus;
			char	minus;
			char	space;
			char	alternate;
			char	period;
		}		n;
	}		booleans;
	char	conversion;
	int		size;
	int		precision;
}				t_modifier;

#define NEW_MODIFIER (t_modifier){{{0, 0, 0, 0, 0, 0}}, '~', 0, 0};

int		is_in(char i, char const *str)
{
	char const	*p = str;

	while (*p != '\0' && *p != i)
		p++;
	return (*p == '\0' ? -1 : p - str);
}

void	db_print_bool(char c)
{
	ft_putstr(c ? "true" : "false");
}

void	db_print_modifier(t_modifier *m)
{
	size_t		n;

	ft_putstr("(t_modifier){\n\t{");
	n = 6;
	while (n-- > 0)
	{
		ft_putstr("\n\t\t");
		db_print_bool(m->booleans.t[5 - n]);
	}
	ft_putstr("\n\t}\n\t'");
	ft_putchar(m->conversion);
	ft_putstr("'\n\t");
	ft_putnbr(m->size);
	ft_putstr("\n\t");
	ft_putnbr(m->precision);
	ft_putstr("\n}\n");
}

int		pf_match(char const **s, t_modifier *m)
{
	int			n;
	char const	c = **s;

	if ((n = is_in(c, "0+- #.")) >= 0)
		m->booleans.t[n] = 1;
	else if ((n = is_in(c, "diouxXDOUeEfFgGaAcCsSpn")) >= 0)
	{
		m->conversion = c;
		return (1);
	}
	else if ('1' <= c && c <= '9')
		while ('0' <= **s && **s <= '9')
		{
			if (m->booleans.n.period)
				m->precision = 10 * m->precision + **s - '0';
			else
				m->size = 10 * m->size + **s - '0';
			(*s)++;
		}
	return (0);
}

int		pf_parse(const char *s, va_list *ap)
{
	t_dyna		d;
	t_modifier	m;
	char		p;

	d = ft_dyna_new(sizeof(char));
	m = NEW_MODIFIER;
	p = 0;
	s--;
	while (*++s != '\0')
	{
		if ((p ^= (*s == '%')) && pf_match(&s, &m))
		{
			pf_convert();
			p = 0;
			m = NEW_MODIFIER;
		}
		else
			ft_dyna_append(&d, (void *)s, 1);
		db_print_modifier(&m);
	}
	write(1, d.data, d.chunck_count);
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;

	va_start(ap, format);
	pf_parse(format, &ap);
	va_end(ap);
	return (0);
}

int		main(int ac, char **av)
{
	char		*s = "(% - + 0i)\n";

	printf(s, 1, -2, 3);
	ft_printf(s, 2, -2, 3);
	return (0);
}
