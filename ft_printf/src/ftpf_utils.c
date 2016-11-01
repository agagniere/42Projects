/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 11:25:39 by angagnie          #+#    #+#             */
/*   Updated: 2016/11/01 08:30:56 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	db_print_bool(char c)
{
	ft_putstr(c ? "true" : "false");
}

void	db_print_modifier(t_modifier *m)
{
	size_t		n;

	ft_putstr("(t_modifier){\n\t{");
	n = 5;
	while (n-- > 0)
	{
		ft_putstr("\n\t\t");
		db_print_bool(m->booleans.t[4 - n]);
	}
	ft_putstr("\n\t}\n\t'");
	ft_putchar(m->conversion);
	ft_putstr("'\n\t'");
	ft_putchar(m->length);
	ft_putstr("'\n\t");
	ft_putnbr(m->size);
	ft_putstr("\n\t");
	ft_putnbr(m->precision);
	ft_putstr("\n}\n");
}

int		is_in(char i, char const *str)
{
	char const	*p = str;

	while (*p != '\0' && *p != i)
		p++;
	return (*p == '\0' ? -1 : p - str);
}
