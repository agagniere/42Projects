/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c										:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:17:02 by angagnie          #+#    #+#             */
/*   Updated: 2015/11/25 16:28:03 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testlibft.h"

void	test_strlen(size_t (*ft)(const char *s))
{
	char const *tests[] = {
		"",
		"1234567890",
		"asd\0qwe",
		"\200 \v\r\t 345 "
	};

	for (unsigned int i = 0 ; i < SIZE_ARRAY(tests) ; i++)
	{
		if (strlen(tests[i]) == ft(tests[i]))
			printf(GREEN);
		else
			printf(RED);
		printf(".");
	}
	printf(END);
}
