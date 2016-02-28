/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:57:03 by tbeauman          #+#    #+#             */
/*   Updated: 2015/11/27 18:37:31 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*t;
	t_list	*lst;

	lst = *alst;
	while (lst)
	{
		t = lst->next;
		del(lst->content, lst->content_size);
		free(lst);
		lst = t;
	}
	*alst = NULL;
}
