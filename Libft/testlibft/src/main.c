/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:20:00 by angagnie          #+#    #+#             */
/*   Updated: 2015/11/29 12:07:29 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testlibft.h"

int		main(void)
{
	int status;

	status = 0;

	FORK(atoi);
	FORK(bzero);

	TESTAC(isalnum);
	TESTAC(isalpha);
	TESTAC(isascii);
//	TESTAC(isblank);
//	TESTAC(iscntrl);
	TESTAC(isdigit);
//	TESTAC(isgraph);
//	TESTAC(islower);
	TESTAC(isprint);
//	TESTAC(ispunct);
//	TESTAC(isspace);
//	TESTAC(isupper);
//	TESTAC(isxdigit);
	TESTAC(tolower);
	TESTAC(toupper);

	FORK(putchar_fd);
	FORK(putnbr);
	FORK(putstr);

	FORK(strlen);
	FORK(memset);
	return (status);
}
