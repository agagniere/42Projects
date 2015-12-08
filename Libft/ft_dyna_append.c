/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyna_append.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:53:40 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/08 20:28:04 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_dyna_append(t_dyna *td, void *data, size_t datalen)
{
	size_t fact;

	if (td->chunck_max == 0)
		ft_dyna_datainit(td);
	if (td->chunck_count + datalen > td->chunck_max)
	{
		fact = 2;
		while (td->chunck_count + datalen > fact * td->chunck_max)
			fact *= DYNA_FACTOR;
		if (ft_dyna_reserve(td, fact * td->chunck_max))
			return (1);
	}
	ft_memcpy(td->data + td->chunck_count * td->chunck_size,
		data, datalen * td->chunck_size);
	td->chunck_count += datalen;
	return (0);
}
