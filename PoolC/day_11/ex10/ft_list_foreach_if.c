/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 22:19:30 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/23 22:44:38 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list,
	void (*f)(void *), void *data_ref, int (*cmp)())
{
	if (!((*cmp)(begin_list->data, data_ref)))
		(*f)(begin_list->data);
	if (begin_list->next)
		ft_list_foreach_if(begin_list->next, f, data_ref, cmp);
}
