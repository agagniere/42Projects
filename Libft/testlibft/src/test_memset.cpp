/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memset.c										:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 08:53:14 by angagnie          #+#    #+#             */
//   Updated: 2015/11/30 16:02:24 by angagnie         ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include "testlibft.h"

static char	*mm()
{
	char *const ans = strdup("1234567");
	bzero(ans, 7);
	return (ans);
}

void	test_memset(void *(*ft)(void *b, int c, size_t len))
{
	char *bees[] = {
		strdup("Hello World"),
		mm(),
		strdup("0123456789ABCDEF Wow now that makes 16 digits OMG"),
		strdup("Nooo")
	};
	int const cees[] = {
		'.',
		'*',
		'_',
		'@'
	};
	size_t const lengths[] = {
		10,
		5,
		40,
		0
	};

	for (unsigned int i = 0 ; i < SIZE_ARRAY(cees) ; i++)
	{
		MARK(!(memcmp(
				   ft(strdup(bees[i]), cees[i], lengths[i]),
				   memset(strdup(bees[i]), cees[i], lengths[i]),
				   lengths[i])), ., "F");
	}
	MARK((memset(bees[0], cees[1], 0) == memset(bees[0], cees[1], 0)), ., "[dst not returned]");
}
