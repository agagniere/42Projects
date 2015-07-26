/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/22 11:21:10 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/26 13:06:18 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*ans;

	if (!(ans = (t_list *)malloc(sizeof(t_list))))
		return (0);
	ans->data = data;
	ans->next = NULL;
	return (ans);
}

t_list	*ft_create_elem_sp(char *data)
{
	t_list	*ans;

	if (!(ans = (t_list *)malloc(sizeof(t_list))))
		return (0);
	ans->data = ft_strdup(data);
	ans->next = NULL;
	return (ans);
}
