/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:27:48 by tbeauman          #+#    #+#             */
/*   Updated: 2015/11/27 18:41:01 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ret;
	size_t	initdstlen;
	size_t	srclen;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	initdstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size < initdstlen)
		return (size + srclen);
	while (dst[j] && j < size)
		j++;
	while (j + 1 < size && src[i])
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	ret = j + 1 == size ? srclen + initdstlen : j;
	return (ret);
}
