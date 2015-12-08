/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memset.c										:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 08:53:14 by angagnie          #+#    #+#             */
//   Updated: 2015/12/08 17:04:24 by angagnie         ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include "testlibft.h"

// # define END_ARRAY(A) ((void*)(A) + sizeof((A))) //version c
# define END_ARRAYCPP(A) ((void*)((char*)(A) + sizeof((A)))) //la version c marche que en c

struct vals_s
{
	char const	*s;
	char 		c;
	size_t		len;
};

struct vals_s const		tests[] =
{
	{"Hello World", '.', 10},
	{"", '*', 5},
	{"0123456789ABCDEF Wow", '_', 30},
	{"Noooo\0\0\0OMG", '@', BUFSIZE},
	{"\0\0\0 Y.S.N.P. \0\0\0", ' ', BUFSIZE},
};


void	test_memset(void *(*ft)(void *b, int c, size_t len))
{
	struct vals_s const		*t = tests;
	char					buf[BUFSIZE];

	while (t < END_ARRAYCPP(tests))
	{
		fun_tester(memset, ft, clear_buf(buf, t->s), t->c, t->len);
		t++;
	}
}
