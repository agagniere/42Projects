/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:55:59 by angagnie          #+#    #+#             */
/*   Updated: 2018/11/28 18:12:30 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_stack.h"
#include "ft_deque_private.h"
#include <limits.h>

int		check_for_duplicates(int *storage, unsigned length, long min, long max)
{
	uint64_t		set[(max - min) / 64];
	long unsigned	elem;

	ft_bzero(set, sizeof(set));
	while (length-- > 0)
	{
		elem = (long)storage[length] - min;
		if (set[elem / 64] & (1UL << (elem % 64)))
			return (1);
		set[elem / 64] |= (1UL << (elem % 64));
	}
	return (0);
}

int		read_args(unsigned ac, char **av, int *storage)
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
			return (1);
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
	int		storage[ac - 1];
	t_stack	stack[1];

	if (ac == 1)
		return (0);
	if (read_args(ac - 1, av + 1, storage))
	{
		FD_PUT(2, "Error");
		return (0);
	}
	stack[0] = STACK_NEW(storage);
	stack->back = ftq_end(stack);
}
