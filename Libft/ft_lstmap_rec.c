/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_rec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 16:28:12 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/06 23:35:21 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** let map l f = match l with
** | []			-> []
** | h :: t		-> (f h) :: (map t f)
** ;;
** let map_ter l f = aux l [] f
** where aux s d f = match s with
** | []			-> dst
** | h :: t		-> (aux t (push_back d h) f)
** ;;
*/

t_list			*ft_lstmap_rec(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *l;
	t_list *r;

	if (lst != NULL)
	{
		l = f(lst);
		r = ft_lstmap_rec(lst->next, f);
		ft_lstadd(&r, ft_lstnew(l->content, l->content_size));
		return (r);
	}
	return (NULL);
}
