/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 17:04:01 by angagnie          #+#    #+#             */
/*   Updated: 2016/10/31 11:21:23 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

#include "ft_printf.h"
#include "libft.h"

int		is_in(char i, char const *str)
{
	char const	*p = str;

	while (*p != '\0' && *p != i)
		p++;
	return (*p == '\0' ? -1 : p - str);
}

void	pf_convert(t_modifier *m, va_list *ap)
{
	int		n;
	void	*f[] = {pfcv_di, pfcv_di}

	n = ft_is_in(m->conversion, FTPF_CV_FLAGS);
	(void (*)())f[n]();
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
	else if ((n = is_in(c, FTPF_CV_FLAGS)) >= 0)
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

void	pf_parse(char const *s, va_list *ap)
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
		if ((p ^= (*s == '%')))
		{
			if (pf_match(&s, &m))
			{
				pf_convert(&m, ap);
				p = 0;
				m = NEW_MODIFIER;
			}
		}
		else
			ft_dyna_append(&d, (void *)s, 1);
		db_print_modifier(&m);
	}
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
	char		*s = "(% 15 - + 0 . 15 i)\n";

	(void)ac;
	(void)av;
	printf(s, 1, -2, 3);
	ft_printf(s, 2, -2, 3);
	return (0);
}
