/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 19:12:09 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/23 22:16:47 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*aux(t_list *current, t_list *previous)
{
	t_list	*ptr;

	ptr = current->next;
	current->next = previous;
	if (current->next)
		return (aux(ptr, current));
	else
		return (current);
}

void	ft_list_reverse(t_list **begin_list)
{
	*begin_list = aux(*begin_list, NULL);
}
