/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:55:59 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/07 18:28:00 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#include "ft_stack.h"
#include "ft_deque_private.h"
#include "ft_prepro.h"
#include "libft.h"
#include "get_next_line.h"
#include "ft_printf.h"
#include "instructions.h"

#include <unistd.h>
#include <stdbool.h>

char	*tmp_iatoa(int *i)
{
	return (ft_itoa(*i));
}

int		tmp_comp(int *a, int *b)
{
	return (*b - *a);
}

bool	execute_instruction(const char *instruction, t_stack *a, t_stack *b)
{
	unsigned	n;
	const char	cmd[][4] = {"sa", "sb", "ss", "pa", "pb", "ra",
							"rb", "rr", "rra", "rrb", "rrr"};
	const t_cmd	t[] = {cmd_sa, cmd_sb, cmd_ss, cmd_pa, cmd_pb, cmd_ra,
						cmd_rb, cmd_rr, cmd_rra, cmd_rrb, cmd_rrr};

	n = 0;
	while (n < ARRAY_LENGTH(t) && ft_strcmp(cmd[n], instruction))
		n++;
	if (n < ARRAY_LENGTH(t))
		t[n](a, b);
	return (n < ARRAY_LENGTH(t));
}

void	read_instructions(int fd, t_stack *a, t_stack *b)
{
	char	*line;

	while (get_next_line(fd, &line) > 0)
	{
		execute_instruction(line, a, b);
		ft_dprintf(2, "\t%s >\t%s\n", line, ftq_string(a, tmp_iatoa));
		ft_dprintf(2, "\t\t%s\n", ftq_string(b, tmp_iatoa));
		free(line);
	}
}

bool	run_pushswap(t_stack *a)
{
	int		storage[a->capacity];
	t_stack	b[1];

	*b = STACK_NEW(storage);
	read_instructions(0, a, b);
	ft_dprintf(2, "Final state :\t%s Top\n", ftq_string(a, tmp_iatoa));
	return (ftq_is_empty(b) && ftq_is_sorted(a, tmp_comp));
}

int		main(int ac, char **av)
{
	int		storage[ac];
	t_stack	stack[1];

	if (ac == 1)
		return (0);
	if (!read_args(ac - 1, av + 1, storage))
	{
		FD_PUT(2, "Error\n");
		return (0);
	}
	*stack = STACK_NEW(storage);
	stack->back = ftq_end(stack) - ftq_offset(stack, 1);
	ft_dprintf(2, "Initial state :\t%s Top\n", ftq_string(stack, tmp_iatoa));
	ft_printf("%s\n", run_pushswap(stack) ? "OK" : "KO");
	return (0);
}
