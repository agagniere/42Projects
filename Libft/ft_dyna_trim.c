/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyna_trim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 18:17:19 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/06 19:36:46 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** http://www.cplusplus.com/reference/vector/vector/shrink_to_fit/
*/

int	ft_dyna_trim(t_dyna *td)
{
	void	*new_data;

	if (td->chunck_count < td-> chunck_max)
	{
		if (!(new_data = malloc(td->chunck_size * td->chunck_count)))
			return (1);
		ft_memcpy(new_data, td->data, td->chunck_count * td->chunck_size);
		free(td->data);
		td->chunck_max = td->chunck_count;
		td->data = new_data;
	}
	return (0);
}
