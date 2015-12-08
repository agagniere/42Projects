/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putnbr.c										:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:59:46 by angagnie          #+#    #+#             */
//   Updated: 2015/12/08 14:02:29 by angagnie         ###   ########.fr       //
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
	int out;
	int p1[2];
	int p2[2];
	char buf1[BUSZ];
	char buf2[BUSZ];

	fflush(stdout);
	bzero(buf1, BUSZ);
	bzero(buf2, BUSZ);
	out = dup(1); // creating a stdout backup
	pipe(p1); // Creating a pipe
	pipe(p2);
	dup2(p1[1], 1); // Moving the pipe for it to read stdout
	for (unsigned int i = 0 ; i < SIZE_ARRAY(tests) ; i++)
	{
		dprintf(p2[1], "%i|", tests[i]);
#ifdef DETAILED
		dprintf(2, "%s%i|", WHITE, tests[i]);
#endif
		ft(tests[i]);
		printf("|");
		fflush(stdout);
	}
	dup2(out, 1); // repairing stdout
	buf1[read(p1[0], buf1, BUSZ - 1)] = 0;
	buf2[read(p2[0], buf2, BUSZ - 1)] = 0;
	close(p1[0]); // closing pipes
	close(p1[1]);
	close(p2[0]);
	close(p2[1]);
	close(out); // we don't need the backup anymore
	MARK(!(strcmp(buf1, buf2)), 5, "F");
}
