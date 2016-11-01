/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 19:38:57 by angagnie          #+#    #+#             */
/*   Updated: 2016/11/01 19:57:46 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ft_printf_private.h"

int		ft_printf(char const *format, ...);
int		ft_dprintf(int fd, char const *format, ...);
int		ft_asprintf(char **ret, char const *format, ...);
int		ft_sprintf(char *s, char const *format, ...);
int		ft_snprintf(char *s, size_t size, char const *format, ...);

int		ft_vprintf(char const *format, va_list ap);
int		ft_vdprintf(int fd, char const *format, va_list ap);
int		ft_vasprintf(char **ret, char const *s, va_list ap);
int		ft_vsprintf(char *s, char const *format, va_list ap);
int		ft_vsnprintf(char *s, size_t size, char const *format, va_list ap);

#endif
