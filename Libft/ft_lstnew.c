/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 15:04:21 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/08 19:42:51 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ans;

	ans = (t_list *)malloc(sizeof(t_list));
	ft_bzero(ans, sizeof(t_list));
	if (content != NULL)
	{
		ans->content_size = content_size;
		ans->content = malloc(content_size);
		ft_memcpy(ans->content, content, content_size);
	}
	ans->next = NULL;
	return (ans);
}
