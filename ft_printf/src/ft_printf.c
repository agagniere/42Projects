/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 17:04:01 by angagnie          #+#    #+#             */
/*   Updated: 2016/11/01 18:37:26 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "ft_printf.h"

void
pf_convert(t_modifier *m, t_dyna *d, va_list *ap)
{
	db_print_modifier(m); // <==

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
	*pf_parse(char const *s, va_list *ap)
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
			pf_convert(&m, &d, ap);
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

int
	ft_printf(char const *format, ...)
{
	va_list		ap;

	va_start(ap, format);
	ft_putstr(pf_parse(format, &ap));
	va_end(ap);
	return (0);
}



int	main(int ac, char **av)
{
	char		*s = "(%h 0hu,%30-20.3.010i,%lllhlhlhhh#x,% zhzhzhzh+- # %)\n";

	(void)ac;
	(void)av;
	printf(s, -2147000123, 2, 987, 13);
	ft_printf(s, -2147000123, 2, 987, 13);
	printf("hh\t%zu\n", sizeof(char));
	printf("h\t%zu\n", sizeof(short));
	printf("\t%zu\n", sizeof(int));
	printf("l\t%zu\n", sizeof(long));
	printf("ll\t%zu\n", sizeof(long long));
	printf("j\t%zu\n", sizeof(intmax_t));
	printf("z\t%zu\n", sizeof(size_t));
	printf("...\t%zu\n", sizeof(__int128));
	return (0);
}
