/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/22 23:27:40 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/22 23:27:49 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		my_list_push_front(t_list **begin_list, void *data)
{
	t_list *rest;

	rest = *begin_list;
	*begin_list = ft_create_elem(data);
	(*begin_list)->next = rest;
}

t_list		*ft_list_push_params(int ac, char **av)
{
	t_list	*ans;
	int		i;

	i = -1;
	ans = 0;
	while (++i < ac)
		my_list_push_front(&ans, av[i]);
	return (ans);
}
