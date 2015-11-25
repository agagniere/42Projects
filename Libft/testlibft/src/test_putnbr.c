/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putnbr.c										:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:59:46 by angagnie          #+#    #+#             */
/*   Updated: 2015/11/25 19:53:40 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testlibft.h"

void	test_putnbr(void (*ft)(int n))
{
	int const tests[] = {
		0,
		99,
		-999,
		2147483647,
		-2147483648
	};

	for (unsigned int i = 0 ; i < SIZE_ARRAY(tests) ; i++)
	{
		printf("%i", tests[i]);
		fflush(stdout);

		ft(tests[i]);
	}
}
