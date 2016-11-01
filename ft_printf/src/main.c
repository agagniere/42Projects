/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 19:15:32 by angagnie          #+#    #+#             */
/*   Updated: 2016/11/01 19:59:34 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // <==

#include "ft_printf.h"

int		main(int ac, char **av)
{
	char const	*s = "(%h 0hu,%30-20.3.010i,%lllhlhlhhh#x,% zhzhzhzh+- # %)\n";

	(void)ac;
	(void)av;
	printf(s, -2147000123, 2, 987, 13);
	ft_printf(s, -2147000123, 2, 987, 13);
	printf("hh\t%zu\n", sizeof(char));
	printf("h\t%zu\n", sizeof(short));
	printf("\t%zu\n", sizeof(int));
	printf("l\t%zu\n", sizeof(long));
	printf("ll\t%zu\n", sizeof(long long));
	printf("j\t%zu\n", sizeof(intmax_t));
	printf("z\t%zu\n", sizeof(size_t));
	printf("...\t%zu\n", sizeof(__int128));
	return (0);
}