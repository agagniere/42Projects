/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 23:24:22 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/23 23:42:42 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	if ((*begin_list)->next)
		ft_list_remove_if(&((*begin_list)->next), data_ref, cmp);
	if (!((*cmp)((*begin_list)->data, data_ref)))
		*begin_list = (*begin_list)->next;
}
