/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcpy.c										:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:24:33 by angagnie          #+#    #+#             */
//   Updated: 2015/12/01 12:42:31 by angagnie         ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include "testlibft.h"

void	test_memcpy(void * (*ft)(void *dst, const void *src, size_t n))
{
	char	buf[BUFSIZE];

	fun_tester(memcpy, ft,  clear_buf(buf, "Destination"), "Source", strlen("Source"));
	fun_tester(memcpy, ft,  clear_buf(buf, "Destination"), "DO NOT COPY", 0);
	fun_tester(memcpy, ft,  clear_buf(buf, "Destination"), "_____\0| To be copied| Not to be !!!!!", 20);
}
