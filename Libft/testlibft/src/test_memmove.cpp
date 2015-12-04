// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   test_memmove.c										:+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/12/04 12:36:36 by angagnie          #+#    #+#             //
//   Updated: 2015/12/04 12:45:04 by angagnie         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "testlibft.h"

void	test_memmove(void	*(*ft)(void *dst, const void *src, size_t len))
{
	char	buf[BUFSIZE + 15];

	fun_tester(memmove, ft, clear_buf(buf, "Where to copy"), "What to copy", strlen("What to copy"));
	fun_tester(memmove, ft, clear_buf(buf, "Where to copyWhat to dupplicate"), buf + strlen("Where to copy"), strlen("What to dupplicate"));
	fun_tester(memmove, ft, clear_buf(buf + 15, "Where to copy"), buf, strlen("What to dupplicate"));
}
