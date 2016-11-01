/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   public.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 19:16:43 by angagnie          #+#    #+#             */
/*   Updated: 2016/11/01 19:27:08 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int
	ft_printf(char const *format, ...)
{
	va_list		ap;
	char		*ans;

	va_start(ap, format);
	ans = ft_vprintf(format, &ap);
	va_end(ap);
	ft_putstr(ans);
	return (ft_strlen(ans));
}

int
	ft_dprintf(int fd, char const *format, ...)
{
	va_list		ap;
	char		*ans;

	va_start(ap, format);
	ans = ft_vprintf(format, &ap);
	va_end(ap);
	write(fd, ans, ft_strlen(ans));
	return (ft_strlen(ans));
}

int
	ft_sprintf(char *str, char const *format, ...)
{
	va_list		ap;
	char		*ans;

	va_start(ap, format);
	ans = ft_vprintf(format, &ap);
	va_end(ap);
	ft_strcpy(str, ans);
	return (ft_strlen(ans));
}

int
	ft_sprintf(char *str, size_t size, char const *format, ...)
{
	va_list		ap;
	char		*ans;

	va_start(ap, format);
	ans = ft_vprintf(format, &ap);
	va_end(ap);
	ft_strncpy(str, ans, size);
	return (ft_strlen(ans));
}
