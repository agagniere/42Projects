/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/26 15:31:30 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/26 18:33:31 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super.h"

void	aux(t_list *begin_list, char **ans)
{
	if (!begin_list)
		return ;
	*ans = begin_list->data;
	aux(begin_list->next, ans + sizeof(*ans));
}

void	*ft_list_merge(t_list *begin_list)
{
	int const	size = ft_list_size(begin_list);
	char		**ans;

	if (!(ans = (char **)malloc(sizeof(begin_list->data) * (size + 1))))
		return (0);
	ans[size] = 0;
	return (ans);
}
