/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bzero.c										:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 15:19:40 by angagnie          #+#    #+#             */
//   Updated: 2015/12/01 13:22:41 by angagnie         ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include "testlibft.h"

void	test_bzero(void (*ft)(void * s, size_t n))
{
	(void)ft;
/*
	char		buf[BUFSIZE];
	auto		reffn = [](void *ptr, size_t n) -> int
	{
		bzero(ptr, n);
		return 42;
	};
	auto		ftfn = [ft](void *ptr, size_t n) -> int
	{
		ft(ptr, n);
		return 42;
	};

	fun_tester(reffn, ftfn, clear_buf(buf, "Should be null | Should not"), 15);
	fun_tester(reffn, ftfn, clear_buf(buf, "Should not be null"), 0);
	fun_tester(reffn, ftfn, clear_buf(buf, "Should be null \0 Should as well"), 30);
*/
}
