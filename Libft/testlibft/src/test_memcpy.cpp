/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcpy.c										:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:24:33 by angagnie          #+#    #+#             */
//   Updated: 2015/11/30 18:06:24 by angagnie         ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include "testlibft.h"

void	test_memcpy(void * (*ft)(void *dst, const void *src, size_t n))
{
	 const char tests[] = {
		// some  values
		 ""
	};

	for (unsigned int i = 0 ; i < SIZE_ARRAY(tests) ; i++)
	{
		fun_tester_na(memcpy, ft,  clear_buf(buf, tests[i]));
	}
	printf(END);
}
