/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:36:55 by angagnie          #+#    #+#             */
/*   Updated: 2015/11/27 11:48:57 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *from;
	unsigned char *to;

	from = (const unsigned char *)src;
	to = (unsigned char *)dst;
	while (n-- > 0)
		*to++ = *from++;
	return (dst);
}
