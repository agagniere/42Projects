// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   test_strlcat.c										:+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/12/03 18:44:51 by angagnie          #+#    #+#             //
//   Updated: 2015/12/04 11:53:00 by angagnie         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "testlibft.h"

void	test_strlcat(size_t (*ft)(char *dst, const char *src, size_t size))
{
	char	buf[BUFSIZE];

	fun_tester(strlcat, ft, clear_buf(buf, "Where to copy : "), "What to copy", BUFSIZE);
	fun_tester(strlcat, ft, clear_buf(buf, "Don't do anything"), "", BUFSIZE);
	fun_tester(strlcat, ft, clear_buf(buf, ""), "What to copy", BUFSIZE);
	fun_tester(strlcat, ft, clear_buf(buf, " > Where to copy ! < "), "What not to copy", strlen(" > Where to copy ! < "));
	fun_tester(strlcat, ft, clear_buf(buf, " > Where to copy ! < "), "What not to copy", strlen(" > Where to copy ! < " + 1));
	fun_tester(strlcat, ft, clear_buf(buf, "Where to copy : \0 To be replaced"), "What to copy", BUFSIZE);
	fun_tester(strlcat, ft, clear_buf(buf, "Where to copy : "), "What to copy | what not to", strlen("Where to copy : What to copy "));
	fun_tester(strlcat, ft, clear_buf(buf, "Where not to copy !"), "What not to copy", 0);
}
