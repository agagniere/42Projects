/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/22 23:34:58 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/26 13:06:38 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super.h"

void	ft_list_clear(t_list **begin_list)
{
	t_list *ptr;
	t_list *tmp;

	if (*begin_list == NULL)
		return ;
	ptr = *begin_list;
	while (ptr)
	{
		tmp = ptr->next;
		free(ptr);
		ptr = tmp;
	}
	*begin_list = NULL;
}
