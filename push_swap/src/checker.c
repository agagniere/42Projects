/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:55:59 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/11 21:10:43 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#include "ft_stack.h"
#include "ft_deque_private.h"
#include "libft.h"
#include "ft_color.h"
#include "get_next_line.h"
#include "ft_printf.h"
#include "instructions.h"

#include <stdbool.h>

static bool
		g_debug = false;

char	*tmp_iatoa(int *i)
{
	return (ft_itoa(*i));
}

int		tmp_comp(int *a, int *b)
{
	return (*b - *a);
}

void	read_instructions(int fd, t_stack *a, t_stack *b)
{
	char	*line;

	while (get_next_line(fd, &line) > 0)
	{
		execute_instruction(line, a, b);
		if (g_debug)
		{
			ft_printf("\t%s%s%s >\t%s\n", COLOR(BOLD), line, COLOR(NORMAL),
					ftq_string(a, tmp_iatoa));
			ft_printf("\t\t%s%s%s\n", COLOR(DIM), ftq_string(b, tmp_iatoa),
					COLOR(NORMAL));
		}
		free(line);
	}
}

bool	run_pushswap(unsigned length, t_stack *a)
{
	int		storage[length];
	t_stack	b[1];

	*b = STACK_NEW(storage);
	read_instructions(0, a, b);
	return (ftq_is_empty(b) && ftq_is_sorted(a, tmp_comp));
}

int		main(int ac, char **av)
{
	int		storage[ac];
	t_stack	stack[1];


	if (ac > 1 && !ft_strcmp(av[1], "-v") && av++ && --ac)
		g_debug = true;
	if (ac == 1)
		return (0);
	if (!read_args(ac - 1, av + 1, storage))
	{
		ft_dprintf(2, "Error\n");
		return (0);
	}
	*stack = STACK_NEW(storage);
	stack->back = ftq_begin(stack) + ftq_offset(stack, ac - 1);
	ft_printf("%s\n", run_pushswap(ac, stack) ? "OK" : "KO");
	return (0);
}
