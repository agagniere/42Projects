/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 19:14:31 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/23 22:07:25 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	if (begin_list == NULL)
		return (NULL);
	else if (nbr == 0)
		return (begin_list);
	else
		return (ft_list_at(begin_list->next, nbr - 1));
}
