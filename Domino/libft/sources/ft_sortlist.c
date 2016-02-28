/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:59:16 by tbeauman          #+#    #+#             */
/*   Updated: 2015/11/26 16:21:48 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	max(size_t a, size_t b)
{
	return (a < b ? b : a);
}

static void		ft_swap(size_t *a, size_t *b)
{
	size_t	tp;

	tp = *a;
	*a = *b;
	*b = tp;
}

t_list			*ft_sort_list(t_list *lst, int (*cmp)(const void *,
			const void *, size_t))
{
	int		ordre;
	t_list	*bgn;
	void	*ctp;

	bgn = lst;
	ordre = 0;
	while (ordre == 0)
	{
		ordre = 1;
		while (lst->next)
		{
			if (cmp(lst->content, lst->next->content, max(lst->content_size,
							lst->next->content_size)) > 0)
			{
				ordre = 0;
				ctp = lst->content;
				lst->content = lst->next->content;
				lst->next->content = ctp;
				ft_swap(&(lst->content_size), &(lst->next->content_size));
			}
			lst = lst->next;
		}
		lst = bgn;
	}
	return (lst);
}
