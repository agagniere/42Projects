/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:08:17 by tbeauman          #+#    #+#             */
/*   Updated: 2015/11/24 14:23:39 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n < ft_strlen(src))
		while (i < n)
		{
			dst[i] = src[i];
			i++;
		}
	else
		while (src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
	while (i < n)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
