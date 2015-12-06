/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyna_datadouble.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:55:52 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/06 19:33:46 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_dyna_datadouble(t_dyna *td, size_t factor)
{
	void	*new_data;

	if (!(new_data = malloc(td->chunck_size * td->chunck_max * factor)))
		return (1);
	ft_memcpy(new_data, td->data, td->chunck_count * td->chunck_size);
	free(td->data);
	td->data = new_data;
	td->chunck_max *= factor;
	return (0);
}
