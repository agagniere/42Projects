/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   public.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 19:16:43 by angagnie          #+#    #+#             */
/*   Updated: 2016/11/01 20:00:07 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char const *format, ...)
{
	va_list		ap;
	int			ans;

	va_start(ap, format);
	ans = ft_vprintf(format, ap);
	va_end(ap);
	return (ans);
}

int		ft_dprintf(int fd, char const *format, ...)
{
	va_list		ap;
	int			ans;

	va_start(ap, format);
	ans = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (ans);
}

int		ft_sprintf(char *s, char const *format, ...)
{
	va_list		ap;
	int			ans;

	va_start(ap, format);
	ans = ft_vsprintf(s, format, ap);
	va_end(ap);
	return (ans);
}

int		ft_snprintf(char *s, size_t size, char const *format, ...)
{
	va_list		ap;
	int			ans;

	va_start(ap, format);
	ans = ft_vsnprintf(s, size, format, ap);
	va_end(ap);
	return (ans);
}
