/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/22 11:21:10 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/22 11:54:18 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*ans;

	if (!(ans = (t_list *)malloc(sizeof(t_list))))
		return (0);
	ans->data = data;
	ans->next = NULL;
	return (ans);
}
