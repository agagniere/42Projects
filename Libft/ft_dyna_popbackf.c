/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyna_popback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 20:08:29 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/08 21:17:16 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dyna_popbackf(t_dyna *td, void (*del)(void *))
{
	if (td->chunck_count > 0)
	{
		td->chunck_count--;
		del(td->data + td->chunck_count * td->chunck_size);
	}
}
