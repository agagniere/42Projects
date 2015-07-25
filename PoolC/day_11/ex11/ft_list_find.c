/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 22:29:54 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/23 22:53:54 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	if (!((*cmp)(begin_list->data, data_ref)))
		return (begin_list);
	else if (begin_list->next)
		return (ft_list_find(begin_list->next, data_ref, cmp));
	else
		return (NULL);
}
