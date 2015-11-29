/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:29:45 by angagnie          #+#    #+#             */
/*   Updated: 2015/11/29 10:22:36 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *one = s1;
	const unsigned char *two = s2;

	if (n == 0)
		return (0);
	while (n-- > 1 && *one == *two)
	{
		++one;
		++two;
	}
	return (*one - *two);
}
