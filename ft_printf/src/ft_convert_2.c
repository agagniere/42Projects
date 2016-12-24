/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 12:37:44 by angagnie          #+#    #+#             */
/*   Updated: 2016/12/24 08:16:37 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>

int		pf_cv_s(t_modifier *m, t_array *d, va_list ap)
{
	char	*arg;
	int		ans;

	arg = va_arg(ap, char *);
	if (arg == NULL)
		arg = "(null)";
	ans = (m->precision >= 0 ? MIN(ft_strlen(arg),
		(size_t)m->precision) : ft_strlen(arg));
	fta_append(d, (void *)arg, ans);
	return (ans);
}

int		pf_cv_ws(t_modifier *m, t_array *d, va_list ap)
{
	wchar_t	*arg;
	int		ans;
	int		len;
	int		cw;

	ans = d->size;
	arg = va_arg(ap, wchar_t *);
	if (arg == NULL)
		arg = L"(null)";
	len = 0;
	while (*arg != L'\0' && len < m->precision)
	{
		cw = 4;
		if (*arg < 1 << 7)
			cw = 1;
		else if (*arg < 0x800)
			cw = 2;
		else if (*arg < 0x10000)
			cw = 3;
		len++;
		ans += cw;
	}
	fta_append(d, arg, ans);
	ans = d->size - ans;
	return (ans);
}

int		pf_cv_c(t_modifier *m, t_array *d, va_list ap)
{
	unsigned char	arg;

	(void)m;
	arg = (char)va_arg(ap, int);
	fta_append(d, (void *)&arg, 1);
	return (1);
}

int		pf_cv_wc(t_modifier *m, t_array *d, va_list ap)
{
	wint_t	arg;

	(void)m;
	arg = va_arg(ap, wint_t);
	if (ABS(arg) < 1 << 7)
	{
		fta_append(d, (void *)&arg, 1);
		return (1);
	}
	else if (ABS(arg) < 1 << 15)
	{
		fta_append(d, (void *)&arg, 2);
		return (2);
	}
	else if (ABS(arg) < 1 << 24)
	{
		fta_append(d, (void *)&arg, 3);
		return (3);
	}
	else
	{
		fta_append(d, (void *)&arg, 4);
		return (4);
	}
}
