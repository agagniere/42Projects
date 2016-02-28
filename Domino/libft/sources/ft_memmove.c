/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:54:28 by tbeauman          #+#    #+#             */
/*   Updated: 2016/01/22 14:02:29 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tab;

	tab = (char*)malloc(len);
	if (!tab)
		return (NULL);
	ft_memcpy(tab, src, len);
	ft_memcpy(dst, tab, len);
	free(tab);
	return (dst);
}
