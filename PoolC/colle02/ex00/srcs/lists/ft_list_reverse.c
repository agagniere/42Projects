/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 19:12:09 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/26 20:53:41 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*aux_rev(t_list *current, t_list *previous)
{
	t_list	*ptr;

	ptr = current->next;
	current->next = previous;
	if (current->next)
		return (aux_rev(ptr, current));
	else
		return (current);
}

void	ft_list_reverse(t_list **begin_list)
{
	if (!begin_list)
		return ;
	*begin_list = aux_rev(*begin_list, 0);
}
