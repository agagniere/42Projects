/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_private.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 19:38:16 by angagnie          #+#    #+#             */
/*   Updated: 2016/12/04 19:47:56 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PRIVATE_H
# define FT_PRINTF_PRIVATE_H

# include <stdarg.h>

# include "libft.h"

# define FTPF_CV "diouxXDOUeEfFgGaAcCsSpn%"
# define FTPF_LM "hljzL"

typedef struct		s_modifier
{
	union
	{
		char		t[5];
		struct
		{
			char	zero;
			char	plus;
			char	minus;
			char	space;
			char	alternate;
		}			n;
	}				booleans;
	char			conversion;
	char			length;
	int				size;
	int				precision;
}					t_modifier;

# define NEW_MODIFIER (t_modifier){{{0, 0, 0, 0, 0}}, 0, 0, 0, 0};

void				db_print_modifier(t_modifier *m);
void				pf_convert(t_modifier *m, t_dyna *d, va_list ap);
int					pf_signed_integer(t_modifier *m,
	t_dyna *d, va_list ap, int b);
int					pf_unsigned_integer(t_modifier *m,
	t_dyna *d, va_list ap, int b);

int					pf_cv_di(t_modifier *m, t_dyna *d, va_list ap);
int					pf_cv_s(t_modifier *m, t_dyna *d, va_list ap);
int					pf_cv_ws(t_modifier *m, t_dyna *d, va_list ap);
int					pf_cv_c(t_modifier *m, t_dyna *d, va_list ap);
int					pf_cv_wc(t_modifier *m, t_dyna *d, va_list ap);
int					pf_cv_o(t_modifier *m, t_dyna *d, va_list ap);
int					pf_cv_x(t_modifier *m, t_dyna *d, va_list ap);
int					pf_cv_cx(t_modifier *m, t_dyna *d, va_list ap);
int					pf_cv_u(t_modifier *m, t_dyna *d, va_list ap);

#endif
