/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_rec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 16:08:52 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/06 19:55:46 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** let push_back l e = match l with
** | []			-> [e]
** | h :: t 	-> h :: (push_back t e)
** ;;
 */
void	ft_lstpush_rec(t_list **alst, t_list *new)
{
	if (*alst == NULL)
		*alst = new;
	else
		ft_lstpush_rec(&((*alst)->next), new);
}
