/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 16:28:12 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/04 17:02:00 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
** let map l f = match l with
** | []			-> []
** | h :: t		-> (f h) :: (map t f)
** ;;
*/
t_list	*ft_lstmap(t_list *lst, t_list * (*f)(t_list *elem))
{
	t_list	*ans;
	t_list	*ptr;

	ptr = f(lst);
	ans = ft_lstnew(ptr->content, ptr->content_size);
	while ((lst = lst->next) != NULL)
	{
		ptr = f(lst);
		ft_lstpush(&ans, ft_listnew(ptr->content, ptr->content_size));
	}
}
