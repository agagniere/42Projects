/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 11:25:39 by angagnie          #+#    #+#             */
/*   Updated: 2017/03/21 13:34:41 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	db_print_bool(char c)
{
	ft_putstr(c ? "true" : "false");
	return ;
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
	ft_putstr("'\n\t'");
	ft_putchar(m->length);
	ft_putstr("'\n\t");
	ft_putnbr(m->size);
	ft_putstr("\n\t");
	ft_putnbr(m->precision);
	ft_putstr("\n}\n");
	return ;
}
