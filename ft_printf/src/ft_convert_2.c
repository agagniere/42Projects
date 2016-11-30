/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 12:37:44 by angagnie          #+#    #+#             */
/*   Updated: 2016/11/30 14:07:11 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		pf_cv_s(t_modifier *m, t_dyna *d, va_list ap)
{
	char	*arg;
	int		ans;

	arg = va_arg(ap, char *);
	ans = (m->precision != 0 ? MIN(ft_strlen(arg),
		(size_t)m->precision) : ft_strlen(arg));
	ft_dyna_append(d, (void *)arg, ans);
	return (ans);
}

int		pf_cv_S(t_modifier *m, t_dyna *d, va_list ap)
{
	wchar_t	*arg;
	int		ans;

	(void)m;
	ans = d->chunck_count;
	arg = va_arg(ap, wchar_t *);
	while (*arg != L'\0')
	{
		if (*arg < 1 << 7)
			ft_dyna_append(d, (void *)arg, 1);
		else if (*arg < 1 << 15)
			ft_dyna_append(d, (void *)arg, 2);
		else if (*arg < 1 << 23)
			ft_dyna_append(d, (void *)arg, 3);
		else
			ft_dyna_append(d, (void *)arg, 4);
		arg++;
	}
	ans = d->chunck_count - ans;
	return (ans);
}

int		pf_cv_c(t_modifier *m, t_dyna *d, va_list ap)
{
	unsigned char	arg;

	arg = va_arg(ap, char);
	ft_dyna_append(d, (void *)&arg, 1);
	return (1);
}

int		pf_cv_C(t_modifier *m, t_dyna *d, va_list ap)
{
	wint_t	arg;

	arg = va_arg(ap, wint_t);
	if (arg < 1 << 7)
	{
		ft_dyna_append(d, (void *)&arg, 1);
		return (1);
	}
	else if (arg < 1 << 15)
	{
		ft_dyna_append(d, (void *)&arg, 2);
		return (2);
	}
	else if (arg < 1 << 24)
	{
		ft_dyna_append(d, (void *)&arg, 3);
		return (3);
	}
	else
	{
		ft_dyna_append(d, (void *)&arg, 4);
		return (4);
	}
}
