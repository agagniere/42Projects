/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putchar_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 10:07:10 by angagnie          #+#    #+#             */
//   Updated: 2015/12/08 14:01:31 by angagnie         ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include "testlibft.h"

void	test_putchar_fd(void (*ft)(char c, int fd))
{
	int		p[2][2];
	char	buf[2][BUSZ];

	fflush(stdout);
	pipe(p[0]);
	pipe(p[1]);
	for (char c = -128 ; c < 127 ; c ++)
	{
		ft(c, p[0][1]);
		dprintf(p[1][1], "%c", c);
	}
	buf[0][read(p[0][0], buf[0], BUSZ - 1)] = '\0';
	buf[1][read(p[1][0], buf[1], BUSZ - 1)] = '\0';
	MARK(!strcmp(buf[0], buf[1]), 256, "F");
	close(p[0][0]);
	close(p[0][1]);
	close(p[1][0]);
	close(p[1][1]);
}
