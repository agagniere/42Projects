/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:36:55 by angagnie          #+#    #+#             */
/*   Updated: 2015/11/24 15:40:35 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned char *from;
	unsigned char *to;

	from = (unsigned char *)src;
	to = (unsigned char *)dst;
	while (n-- > 0)
		*to++ = *from++;
	return (dst);
}
