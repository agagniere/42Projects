/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:37:36 by angagnie          #+#    #+#             */
/*   Updated: 2016/11/06 01:14:40 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_cv_di(t_modifier *m, t_dyna *d, va_list ap)
{
	int		arg;

	arg = va_arg(ap, int);
	return (1);
}

int		pf_cv_str(t_modifier *m, t_dyna *d, va_list ap)
{
	char	*arg;
	int		ans;

	arg = va_arg(ap, char *);
	ans = (m->precision == 0 ? ft_strlen(arg) : m->precision);
	ft_dyna_append(d, (void *)arg, ans);
	return (ans);
}
