/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 14:12:37 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/08 18:04:23 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	ret;

	dst_len = ft_strlen(dst);
	ret = ft_strlen(src) + (size < dst_len ? size : dst_len);
	dst += dst_len;
	while ((++dst_len) < size && *src != '\0')
		*dst++ = *src++;
	*dst = '\0';
	return (ret);
}
