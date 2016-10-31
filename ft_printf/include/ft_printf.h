/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 10:45:13 by angagnie          #+#    #+#             */
/*   Updated: 2016/10/31 10:46:05 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FTPF_CV_FLAGS "diouxXDOUeEfFgGaAcCsSpn"

typedef struct	s_modifier
{
	union
	{
		char	t[6];
		struct
		{
			char	zero;
			char	plus;
			char	minus;
			char	space;
			char	alternate;
			char	period;
		}		n;
	}		booleans;
	char	conversion;
	int		size;
	int		precision;
}				t_modifier;

#define NEW_MODIFIER (t_modifier){{{0, 0, 0, 0, 0, 0}}, '~', 0, 0};