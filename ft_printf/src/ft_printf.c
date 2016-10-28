/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 17:04:01 by angagnie          #+#    #+#             */
/*   Updated: 2016/10/28 17:40:41 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libft.h"

typedef	struct	s_modifier
{
	union
	{
		char	t[5];
		struct
		{
			char	zero;
			char	plus;
			char	minus;
			char	space;
			char	alternate;
		}		n;
	}		booleans;
	char	conversion;
	int		size;
	int		precision;
}				t_modifier;

#define NEW_MODIFIER (t_modifier){{{0, 0, 0, 0, 0}}, 0, 0, 0};

int		is_in(char i, char const *str)
{
	char const	*p = str;

	while (*p != '\0' && *p != i)
		p++;
	return (*p == '\0' ? -1 : p - str);
}

int		pf_match(char i, t_modifier *m)
{
	int			n;

	if ((n = is_in(i, "0+- #")) >= 0)
		m->booleans.t[n] = 1;
	else if ((n = is_in(i, "diouxXDOUeEfFgGaAcCsSpn")) >= 0)
	{
		m->conversion = i;
		return (0);
	}
	return (1);
}

int		pf_parse(const char *s, ...)
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
		if ((p ^= (*s == '%')) && (p = pf_match(*s, &m)))
		{
			pf_;
			m = NEW_MODIFIER;
		}
		else
			ft_dyna_append(&d, (void *)s, 1);
	}
	write(1, d.data, d.chunck_count);
	return (0);
}

int		ft_printf(const char *format, ...)
{
	pf_parse(format);
	return (0);
}

int		main(int ac, char **av)
{
	char		*s = "(% - + 0i)\n";

	printf(s, 1, -2, 3);
	ft_printf(s, 2, -2, 3);
	return (0);
}
