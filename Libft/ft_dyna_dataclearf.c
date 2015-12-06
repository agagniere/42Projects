/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyna_dataclearf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:46:25 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/06 18:04:35 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dyna_dataclearf(t_dyna t, void (*del)(void *))
{
	if (t->chunck_max > 0)
	{
		del(t->data);
		t->chunck_count = 0;
		t->chunck_max = 0;
	}
}
