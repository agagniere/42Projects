/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:34:13 by tbeauman          #+#    #+#             */
/*   Updated: 2015/11/26 15:29:13 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ret;
	void	*ccpy;
	size_t	scpy;

	ccpy = malloc(sizeof(content));
	scpy = content_size;
	ret = (t_list*)malloc(sizeof(t_list));
	if (!ret)
		return (NULL);
	if (!content)
	{
		ret->content = NULL;
		ret->content_size = 0;
		ret->next = NULL;
		return (ret);
	}
	ft_memcpy(ccpy, content, content_size);
	ret->content = ccpy;
	ret->content_size = scpy;
	ret->next = NULL;
	return (ret);
}
