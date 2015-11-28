/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:58:58 by angagnie          #+#    #+#             */
/*   Updated: 2015/11/28 15:08:42 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testlibft.h"

void	test_atoi(int (*ft)(const char *str))
{
	int		status;
	char	*tests[] = {
		"",
		"-0",
		"     +1",
		"123",
		"-1230",
		" \t 567",
		" \r +654 Hello There",
		" \f 987 Noooo",
		"++3",
		" \v -000000789",
		"-2147483648",
		"2147483647",
		NULL
	};

	for (unsigned int i = 0 ; i < SIZE_ARRAY(tests) ; i++)
		YDNHS(atoi(tests[i]) == ft(tests[i]), strcln(tests[i]));
}
