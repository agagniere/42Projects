/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyna_datainit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:30:41 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/06 19:34:55 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_dyna_datainit(t_dyna *td)
{
	if (!(td->data = malloc(td->chunck_size * DYNA_INITIAL_SIZE)))
		return (1);
	td->chunck_max = DYNA_INITIAL_SIZE;
	td->chunck_count = 0;
	return (0);
}
