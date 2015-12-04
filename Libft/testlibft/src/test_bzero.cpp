/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bzero.c										:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 15:19:40 by angagnie          #+#    #+#             */
//   Updated: 2015/12/04 12:16:52 by angagnie         ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include "testlibft.h"

static void			(*ftft)(void*,size_t);

int			reffn(void *ptr, size_t n)
{
	bzero(ptr, n);
	return 42;
}

int			ftfn(void *ptr, size_t n)
{
	ftft(ptr, n);
	return 42;
}

// j'ai rien trouve de plus beau
void	test_bzero(void (*ft)(void * s, size_t n))
{
	char		buf[BUFSIZE];

	ftft = ft;
	fun_tester(reffn, ftfn, clear_buf(buf, "Should be null | Should not"), 15);
	fun_tester(reffn, ftfn, clear_buf(buf, "Should not be null"), 0);
	fun_tester(reffn, ftfn, clear_buf(buf, "Should be null \0 Should as well"), 30);
}
