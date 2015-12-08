/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:20:00 by angagnie          #+#    #+#             */
//   Updated: 2015/12/08 17:11:48 by angagnie         ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include "testlibft.h"

int status = 0;

int		main(void)
{
#ifdef DETAILED
	std::cout << WHITE << "(detailed)" << END << std::endl;
#endif
	printf("%s\t\t-== Start ==-%s\n", GREEN, END);

	FORK(atoi);
	FORK(bzero);

	TESTAC(isalnum);
	TESTAC(isalpha);
	TESTAC(isascii);
	TESTAC(isblank);
	TESTAC(iscntrl);
	TESTAC(isdigit);
	TESTAC(isgraph);
	TESTAC(islower);
	TESTAC(isprint);
	TESTAC(ispunct);
	TESTAC(isspace);
	TESTAC(isupper);
	TESTAC(isxdigit);
	TESTAC(tolower);
	TESTAC(toupper);

	FORK(putchar_fd);
	FORK(putnbr);
	FORK(putstr);

	FORK(strcpy);
	FORK(strlen);
	FORK(memcpy);
	FORK(memchr);
	FORK(strlcat);
	FORK(memcmp);
	FORK(memmove);
	FORK(strcat);
	test_dyna();

	printf("%s\t\t-=== End ===-%s\n", GREEN, END);
	return (0);
}
