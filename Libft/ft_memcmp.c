/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:29:45 by angagnie          #+#    #+#             */
/*   Updated: 2015/11/25 12:35:48 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char const *one = (unsigned char *)s1;
	unsigned char const *two = (unsigned char *)s2;

	if (n == 0)
		return (0);
	while (n-- > 0 && *one == *two)
	{
		++one;
		++two;
	}
	return (*one - *two);
}
