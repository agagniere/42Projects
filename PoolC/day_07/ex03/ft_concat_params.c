/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/17 08:10:37 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/17 08:39:54 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char *ft_concat_params(int argc, char **argv)
{
	char	*total;
	int		ts;
	int		ti;
	int		a;

	ts = 0;
	a = argc;
	while (--a > 0)
	{
		ti = -1;
		while (argv[a][++ti] != 0)
			++ts;
	}
	ts += argc - 3;
	total = malloc(sizeof(char) * ts);
	ts = -1;
	while (++a < argc)
	{
		ti = -1;
		while (argv[a][++ti] != 0)
			total[++ts] = argv[a][ti];
		if (a < argc - 1)
			total[++ts] = '\n';
	}
	return (total);
}
