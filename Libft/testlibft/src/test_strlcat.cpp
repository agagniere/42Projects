// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   test_strlcat.c										:+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/12/03 18:44:51 by angagnie          #+#    #+#             //
//   Updated: 2015/12/08 17:58:57 by angagnie         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "testlibft.h"

void	test_strlcat(size_t (*ft)(char *dst, const char *src, size_t size))
{
	char	buf[BUFSIZE];

	memset(buf, ' ', BUFSIZE);
	fun_tester(strlcat, ft, strcpy(buf, "Where to copy : "), "What to copy", BUFSIZE);
	memset(buf, ' ', BUFSIZE - 1);
	fun_tester(strlcat, ft, strcpy(buf, "Don't do anything"), "", BUFSIZE - 3);
	memset(buf, ' ', BUFSIZE - 1);
	fun_tester(strlcat, ft, strcpy(buf, ""), "What to copy", BUFSIZE - 10);
	fun_tester(strlcat, ft, clear_buf(buf, " > Where to copy ! < "), "What not to copy", strlen(" > Where to copy ! < ") - 1);
	fun_tester(strlcat, ft, clear_buf(buf, " > Where to copy ! < "), "What not to copy", strlen(" > Where to copy ! < "));
	fun_tester(strlcat, ft, clear_buf(buf, " > Where to copy ! < "), "What not to copy", strlen(" > Where to copy ! < ") + 1);
	fun_tester(strlcat, ft, clear_buf(buf, "Where to copy : \0 To be replaced"), "What to copy", BUFSIZE);
	fun_tester(strlcat, ft, clear_buf(buf, "Where to copy : "), "What to copy | what not to", strlen("Where to copy : What to copy "));
	fun_tester(strlcat, ft, clear_buf(buf, "Where not to copy !"), "What not to copy", 0);
}
