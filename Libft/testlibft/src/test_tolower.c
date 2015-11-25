/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tolower.c										:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:46:07 by angagnie          #+#    #+#             */
/*   Updated: 2015/11/25 16:59:49 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testlibft.h"

void	test_tolower(int (*ft)(int c))
{
	char const tests[] = {
		'a',
		'A',
		'w',
		'W',
		-65,
		127,
		-128,
		'0'
	};

	for (unsigned int i = 0 ; i < SIZE_ARRAY(tests) ; i++)
	{
		if (tolower(tests[i]) == ft(tests[i]))
			printf(GREEN);
		else
			printf(RED);
		printf(".");
	}
	printf(END);
}
