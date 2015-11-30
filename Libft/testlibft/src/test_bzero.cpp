/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bzero.c										:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 15:19:40 by angagnie          #+#    #+#             */
/*   Updated: 2015/11/30 12:37:37 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testlibft.h"

#define TOTAL 15

void	test_bzero(void (*ft)(void * s, size_t n))
{
	char	*buf1;
	char	*buf2;

	for (int i = 0 ; i <= TOTAL ; i++)
	{
		buf1 = (char *)memset(malloc(TOTAL + 1), '0' + i, TOTAL);
		buf2 = (char *)memset(malloc(TOTAL + 1), '0' + i, TOTAL);
		buf1[TOTAL] = '\0';
		buf2[TOTAL] = '\0';
		bzero(buf1, i);
		ft(buf2, i);
		MARK(!memcmp(buf1, buf2, i), ., "F");
	}
}
