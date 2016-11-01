/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_private.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 19:38:16 by angagnie          #+#    #+#             */
/*   Updated: 2016/11/01 19:38:27 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PRIVATE_H
# define FT_PRINTF_PRIVATE_H

# include <stdarg.h>

# include "libft.h"

# define FTPF_CV "diouxXDOUeEfFgGaAcCsSpn%"
# define FTPF_LM "hljz"

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

void	pfcv_di(t_modifier *m, va_list *ap, t_dyna *d);
int		is_in(char i, char const *str);
void	db_print_modifier(t_modifier *m);

#endif
