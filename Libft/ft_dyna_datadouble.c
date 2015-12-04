/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyna_datadouble.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:55:52 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/04 18:13:22 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_dyna_datadouble(t_dyna *td)
{
	void	*new_data;

	if (!(new_data = malloc(td->chunck_size * td->chunck_max * DYNA_FACTOR)))
		return (1);
	ft_memcpy(new_data, td->data, td->chunk_count * td->chunck_size);
	free(td->data);
	td->data = new_data;
	td->chunck_max *= DYNA_FACTOR;
	return(0);
}
