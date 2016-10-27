/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 17:04:01 by angagnie          #+#    #+#             */
/*   Updated: 2016/10/27 21:00:18 by angagnie         ###   ########.fr       */
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

typedef struct	s_progress
{
	char	percent;
	char	period;
	char	notsureaboutthisone;
}				t_progress;

#define NEW_MODIFIER (t_modifier){{{0, 0, 0, 0, 0}}, 0, 0, 0};

void	tp_percent(t_modifier *m, t_progress *p)
{
	p->percent ^= 1;
}

void	tp_period(t_modifier *m, t_progress *p)
{
	p->period = 1;
}

int		pf_match(char i, t_modifier *m, t_progress *p)
{
	char const		*b = "0+- #";
	char const		c[] = {'%', '.'};
	void			*f[] = {&tp_percent, &tp_period};
	char			*s[] = {"diouxXDOUeEfFgGaAcCsSpn", ""};
	void			*g = {};
	const size_t	l = 2;
	int				n;
	char const		*a;

	a = b - 1;
	while (*++a != '\0')
		if (*a == i)
		{
			m->booleans.t[a-b] = 1;
			return (1);
		}
	n = l;
	while (n-- > 0)
		if (c[n] == i)
		{
			((void (*)())f[n])(m, p);
			return (1);
		}
	return (0);
}

int		pf_parse(const char *s)
{
	t_dyna		d;
	t_modifier	m;
	t_progress	p;

	d = ft_dyna_new(sizeof(char));
	m = NEW_MODIFIER;
	p = (t_progress){0,0,0};
	s--;
	while (*++s != '\0')
	{
		pf_match(*s, &m, &p);
		if (!p.percent)
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
	char		*s = "(%+-0%i,%d,%i)\n";

	printf(s, 1, -2, 3);
	ft_printf(s, 12, -2., 3.);
	return (0);
}
