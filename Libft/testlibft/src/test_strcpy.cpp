/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcpy.c										:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:37:13 by angagnie          #+#    #+#             */
//   Updated: 2015/12/01 11:14:23 by angagnie         ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include "testlibft.h"

void	test_strcpy(char *(*ft)(char *dst, char const *src))
{
	char buf[BUFSIZE];

	fun_tester(strcpy, ft, clear_buf(buf), "To be copied");
	fun_tester(strcpy, ft, clear_buf(buf, "You should not modify this"), "");
	fun_tester(strcpy, ft, clear_buf(buf, "Before"), "After");
}
