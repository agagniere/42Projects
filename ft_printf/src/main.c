/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 19:15:32 by angagnie          #+#    #+#             */
/*   Updated: 2016/11/05 15:45:42 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

int		main(int ac, char **av)
{
	char const	*s = "(%020.10i,%0-20.5s)\n";

	(void)ac;
	(void)av;
	printf(s, 'a', "Hello World !");
	ft_printf(s, 'a', "Hello World !");
/*	printf("hh\t%zu\n", sizeof(char));
	printf("h\t%zu\n", sizeof(short));
	printf("\t%zu\n", sizeof(int));
	printf("l\t%zu\n", sizeof(long));
	printf("ll\t%zu\n", sizeof(long long));
	printf("j\t%zu\n", sizeof(intmax_t));
	printf("z\t%zu\n", sizeof(size_t));
	printf("...\t%zu\n", sizeof(__int128));
	printf("f\t%zu\n", sizeof(float));
	printf("lf\t%zu\n", sizeof(double));
	printf("Lf\t%zu\n", sizeof(long double));*/
	return (0);
}
