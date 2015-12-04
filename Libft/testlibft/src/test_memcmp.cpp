// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   test_memcmp.c										:+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/12/04 11:54:19 by angagnie          #+#    #+#             //
//   Updated: 2015/12/04 12:08:47 by angagnie         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "testlibft.h"

void	test_memcmp(int (*ft)(const void *s1, const void *s2, size_t n))
{
	char	buf[BUFSIZE];


	fun_tester(memcmp, ft, clear_buf(buf, "The same value"), "The same value", BUFSIZE);
	fun_tester(memcmp, ft, clear_buf(buf, "Some value"), "Some other value", BUFSIZE);
	fun_tester(memcmp, ft, clear_buf(buf, "Not strcmp\0\0 You noob"), "Not strcmp\0\0 :p", BUFSIZE);
	fun_tester(memcmp, ft, clear_buf(buf, "Some value"), "Some kinda same value...", 5);
	fun_tester(memcmp, ft, clear_buf(buf, "Hello"), "World", 0);
}
