/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/22 14:46:02 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/26 21:32:55 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int			local_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void		ft_list_push_back(t_list **begin_list, void *data)
{
	if (!*begin_list)
		*begin_list = ft_create_elem(data);
	else if (!((*begin_list)->next))
		(*begin_list)->next = ft_create_elem(data);
	else
		ft_list_push_back(&((*begin_list)->next), data);
}

void		ft_list_push_back_once(t_list **begin_list, void *data)
{
	if (!*begin_list)
		*begin_list = ft_create_elem(data);
	else if (local_strcmp((*begin_list)->data, data))
		return ;
	else if (!((*begin_list)->next))
		(*begin_list)->next = ft_create_elem(data);
	else
		ft_list_push_back(&((*begin_list)->next), data);
}
