/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcpy.c										:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:24:33 by angagnie          #+#    #+#             */
/*   Updated: 2015/11/27 17:25:56 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testlibft.h"

void	test_memcpy(void * (*ft)(void *dst, const void *src, size_t n))
{
	 const tests[] = {
		// some  values
	};

	for (unsigned int i = 0 ; i < SIZE_ARRAY(tests) ; i++)
	{
		MARK(memcpy(tests[i]) == ft(tests[i]));
	}
	printf(END);
}
