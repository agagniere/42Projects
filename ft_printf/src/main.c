/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 19:15:32 by angagnie          #+#    #+#             */
/*   Updated: 2016/11/02 17:52:11 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // <==

#include "ft_printf.h"

int		main(int ac, char **av)
{
	char const	*s = "(%5- i,%i,%i,%%)\n";

	(void)ac;
	(void)av;
	printf(s, 42, 2, 3, 4);
	ft_printf(s, 1, 2, 3, 4);
	printf("hh\t%zu\n", sizeof(char));
	printf("h\t%zu\n", sizeof(short));
	printf("\t%zu\n", sizeof(int));
	printf("l\t%zu\n", sizeof(long));
	printf("ll\t%zu\n", sizeof(long long));
	printf("j\t%zu\n", sizeof(intmax_t));
	printf("z\t%zu\n", sizeof(size_t));
	printf("...\t%zu\n", sizeof(__int128));
	printf("f\t%zu\n", sizeof(float));
	printf("lf\t%zu\n", sizeof(double));
	printf("Lf\t%zu\n", sizeof(long double));
	return (0);
}
