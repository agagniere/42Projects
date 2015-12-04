/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:58:58 by angagnie          #+#    #+#             */
//   Updated: 2015/12/04 11:02:48 by angagnie         ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include "testlibft.h"

void	test_atoi(int (*ft)(const char *str))
{
	int		status;
	char const	*tests[] = {
		"",
		"-0",
		"     +1",
		"123",
		"-1230",
		" \t 567",
		" \r +654 Hello There",
		" \f 987 Noooo",
		"++3",
		"_987",
		" \n 49376 876",
		" \v -000000789",
		"-2147483648",
		"2147483647"
	};

	for (unsigned int i = 0 ; i < SIZE_ARRAY(tests) ; i++)
	{
		MARKF((atoi(tests[i]) == ft(tests[i])), _, strcln(tests[i]));
	}
}
