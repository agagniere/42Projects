/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:55:59 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/05 19:04:09 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include "ft_deque_private.h"
#include "libft.h"
#include "ft_bitset.h"

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
	unsigned			n = ac;

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

int		main(int ac, char **av)
{
	int		storage[ac];
	t_stack	stack[1];

	if (ac == 1)
		return (0);
	if (!read_args(ac - 1, av + 1, storage))
	{
		FD_PUT(2, "Error");
		return (0);
	}
	*stack = STACK_NEW(storage);
	stack->back = ftq_end(stack) - ftq_offset(stack, 1);
}
