/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:55:59 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/06 19:01:44 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bitset.h"
#include "libft.h"

#include <limits.h>
#include <stdbool.h>

bool	check_for_duplicates(int *storage, unsigned length, long min, long max)
{
	t_bitset		set[(max - min) / sizeof(t_bitset)];
	long unsigned	elem;

	ft_bzero(set, sizeof(set));
	while (length-- > 0)
	{
		elem = (long)storage[length] - min;
		if (BITSET_GET(set, elem))
			return (false);
		BITSET_SET(set, elem);
	}
	return (true);
}

bool	read_args(unsigned ac, char **av, int *storage)
{
	int					max;
	int					min;
	unsigned			n;

	n = ac;
	max = INT_MIN;
	min = INT_MAX;
	while (n-- > 0)
	{
		storage[n] = ft_atoi(*av);
		if (storage[n] == 0 && **av != '0')
			return (false);
		if (max < storage[n])
			max = storage[n];
		if (storage[n] < min)
			min = storage[n];
		av++;
	}
	return (check_for_duplicates(storage, ac, min, max));
}
