/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 19:04:35 by angagnie          #+#    #+#             */
/*   Updated: 2015/11/25 11:55:10 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char const		*from = (unsigned char *)src;
	unsigned char			*to;

	to = (unsigned char *)dst;
	while (n-- > 0)
	{
		*to = *from;
		if (*to == (unsigned char)c)
			return (to + 1);
		++to;
		++from;
	}
	return (NULL);
}
