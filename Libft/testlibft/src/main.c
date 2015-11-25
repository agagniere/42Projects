/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:20:00 by angagnie          #+#    #+#             */
/*   Updated: 2015/11/25 21:46:03 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testlibft.h"

#define TEST(FUN) printf("%s", #FUN);			\
	test_##FUN(&ft_##FUN);						\
	printf("\n")

#define TESTAC(FUN) printf("%s", #FUN);			\
	test_allchar(&ft_##FUN, &FUN);		\
	printf("\n")

int		main(void)
{
	TEST(atoi);
	TEST(strlen);
	TESTAC(tolower);
	TESTAC(toupper);
	TESTAC(isalnum);
	TESTAC(isalpha);
	TESTAC(isascii);
	TESTAC(isblank);
	TESTAC(iscntrl);
	TESTAC(isdigit);
	TESTAC(isprint);
	TESTAC(isspace);
	TESTAC(isupper);
	TESTAC(islower);
	TEST(putnbr);
	return (0);
}
