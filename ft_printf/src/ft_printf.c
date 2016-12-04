/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   public.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 19:16:43 by angagnie          #+#    #+#             */
/*   Updated: 2016/12/04 20:52:58 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** _format_ is the string describing the expected output,
** the data being given through a unknown number
** of parameters following _format_.
** All those functions return the number of bytes written.
*/

/*
** Writes on the standard output.
*/

int		ft_printf(char const *format, ...)
{
	va_list		ap;
	int			ans;

	va_start(ap, format);
	ans = ft_vprintf(format, ap);
	va_end(ap);
	return (ans);
}

/*
** Writes on the provided file descriptor _fd_.
*/

int		ft_dprintf(int fd, char const *format, ...)
{
	va_list		ap;
	int			ans;

	va_start(ap, format);
	ans = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (ans);
}

/*
** Writes in the provided string _s_.
*/

int		ft_sprintf(char *s, char const *format, ...)
{
	va_list		ap;
	int			ans;

	va_start(ap, format);
	ans = ft_vsprintf(s, format, ap);
	va_end(ap);
	return (ans);
}

/*
** Writes into the provided string _s_, but not more than _size_ bytes
*/

int		ft_snprintf(char *s, size_t size, char const *format, ...)
{
	va_list		ap;
	int			ans;

	va_start(ap, format);
	ans = ft_vsnprintf(s, size, format, ap);
	va_end(ap);
	return (ans);
}

/*
** Allocates a string, writes into it, and returns it through _ret_
*/

int		ft_asprintf(char **ret, char const *format, ...)
{
	va_list		ap;
	int			ans;

	va_start(ap, format);
	ans = ft_vasprintf(ret, format, ap);
	va_end(ap);
	return (ans);
}
