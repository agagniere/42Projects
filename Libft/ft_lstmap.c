/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 16:28:12 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/08 20:19:16 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** let map l f = match l with
** | []			-> []
** | h :: t		-> (f h) :: (map t f)
** ;;
*/

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	return (ft_lstmap_rec(lst, f));
}
