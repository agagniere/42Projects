// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   test_memchr.c										:+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/12/01 13:10:37 by angagnie          #+#    #+#             //
//   Updated: 2015/12/01 13:14:20 by angagnie         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "testlibft.h"

void	test_memchr(void* (*ft)(const void *s, int c, size_t n))
{
	char	buf[BUFSIZE];

	fun_tester(memchr, ft, clear_buf(buf, "Some value"), 'v', strlen("Some value"));
	fun_tester(memchr, ft, clear_buf(buf, "Some value"), 'z', strlen("Some value"));
	fun_tester(memchr, ft, clear_buf(buf, "Some value"), 'S', strlen("Some value"));
	fun_tester(memchr, ft, clear_buf(buf, "Some value"), '\0', strlen("Some value"));
	fun_tester(memchr, ft, clear_buf(buf, "Some value"), 'v', 0);
	fun_tester(memchr, ft, clear_buf(buf, "Some value"), 'e', strlen("Some value"));
}
