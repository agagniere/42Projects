/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_rec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 16:21:29 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/04 16:45:03 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel_rec(t_list **alst,
	void (*del)(void *content, size_t content_size))
{
	if (*alst != NULL)
	{
		ft_lstdel_rec(&((*alst)->next), del);
		ft_lstdelone(alst, del);
		*alst = NULL;
	}
}
