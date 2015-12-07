/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyna_trim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 18:17:19 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/07 22:09:14 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** http://www.cplusplus.com/reference/vector/vector/shrink_to_fit/
*/

int	ft_dyna_trim(t_dyna *td)
{
	if (td->chunck_count < td->chunck_max)
	{
		if (!(td->data = ft_realloc(td->data,
			td->chunck_max, td->chunck_count, td->chunck_size)))
			return (1);
		td->chunck_max = td->chunck_count;
	}
	return (0);
}
