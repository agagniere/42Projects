/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyna_reserve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 20:10:30 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/08 12:49:23 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_dyna_reserve(t_dyna *td, size_t size)
{
	if (size > td->chunck_max)
	{
		if (!(td->data = ft_realloc(td->data,
			td->chunck_count, size, td->chunck_size)))
			return (1);
		td->chunck_max = size;
	}
	return (0);
}
