/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   public_v.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 19:16:43 by angagnie          #+#    #+#             */
/*   Updated: 2016/12/04 12:12:56 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_vprintf(char const *format, va_list ap)
{
	return (ft_vdprintf(1, format, ap));
}

int		ft_vdprintf(int fd, char const *format, va_list ap)
{
	char		*str;
	int			ans;

	ans = ft_vasprintf(&str, format, ap);
	write(fd, str, ans);
	free(str);
	return (ans);
}

int		ft_vsprintf(char *s, char const *format, va_list ap)
{
	char		*str;
	int			ans;

	ans = ft_vasprintf(&str, format, ap);
	ft_strcpy(s, str);
	free(str);
	return (ans);
}

int		ft_vsnprintf(char *s, size_t size, char const *format, va_list ap)
{
	char		*str;
	int			ans;

	ans = ft_vasprintf(&str, format, ap);
	ft_strncpy(s, str, size);
	free(str);
	return (ans);
}
