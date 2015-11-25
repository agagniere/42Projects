/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:58:58 by angagnie          #+#    #+#             */
/*   Updated: 2015/11/25 15:22:09 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testlibft.h"

void	test_atoi(int (*ft)(const char *str))
{
	char const *tests[] = {
		"",
		"0",
		"     -1",
		"123",
		"-1230",
		"\t567",
		"\r654ert",
		"++3",
		"\v-000000789",
		"-2147483648",
		"2147483647"
	};

	for (unsigned int i = 0 ; i < SIZE_ARRAY(tests) ; i++)
	{
		if (atoi(tests[i]) == ft(tests[i]))
			printf(GREEN);
		else
			printf(RED);
		printf(".");
		printf(END);
	}
}
