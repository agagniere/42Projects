/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 15:56:29 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/04 16:49:30 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush(t_list **alst, t_list *new)
{
	if (*alst == NULL)
		*alst = new;
	else
	{
		while ((*alst)->next != NULL)
		{
			*alst = (*alst)->next;
		}
		(*alst)->next = new;
	}
}
