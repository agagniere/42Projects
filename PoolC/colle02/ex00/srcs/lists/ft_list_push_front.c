/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/22 18:45:09 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/26 13:07:22 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *rest;

	rest = *begin_list;
	*begin_list = ft_create_elem(data);
	(*begin_list)->next = rest;
}

void	ft_list_push_front_sp(t_list **begin_list, char *data)
{
	t_list *rest;

	rest = *begin_list;
	*begin_list = ft_create_elem_sp(data);
	(*begin_list)->next = rest;
}
