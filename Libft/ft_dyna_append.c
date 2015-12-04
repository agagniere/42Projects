/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyna_append.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:53:40 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/04 18:14:10 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_dyna_append(t_dyna *td, void *data, size_t datalen)
{
	if (td->chunck_count + datalen > td->chunck_max)
		if (ft_dyna_datadouble(td))
			return (1);
	ft_memcpy(td->data + td->chunck_count * td->chunck_size,
		data, datalen * td->chunck_size);
	td->chunck_count += datalen;
	return (0);
}
