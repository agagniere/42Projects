/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 19:04:35 by angagnie          #+#    #+#             */
/*   Updated: 2015/11/28 09:24:32 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char const		*from;
	unsigned char			*to;

	from = src;
	to = dst;
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
