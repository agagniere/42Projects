/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_convert1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 10:44:16 by angagnie          #+#    #+#             */
/*   Updated: 2016/10/31 11:44:13 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	pfcv_di(t_modifier *m, va_list *ap, t_dyna *d)
{
	int const	p = va_arg(*ap, int);

	if (m->booleans.n.plus)
		ft_dyna_append(d, p < 0 ? "-" : "+", 1);
	else if (m->booleans.n.space)
		ft_dyna_append(d, " ", 1);
}
