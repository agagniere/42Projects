/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:43:52 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/11 21:18:36 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#include "ft_printf.h"
#include "ft_array.h"
#include "ft_stack.h"
#include "ft_deque_private.h"
#include "libft.h"
#include "instructions.h"

#define ELEM(S) (S[0]+(S[1]<<8)+(S[2]<<16))

bool	add_instruction(t_array *program, t_stack *a, t_stack *b,
						const char *str)
{
	unsigned	elem;

	elem = ELEM(str);
	fta_append(program, &elem, 1);
	execute_instruction(str, a, b);
}

void	select_sort(t_array *program, t_stack *a, t_stack *b)
{

}

t_array	get_instructions(unsigned length, t_stack *a)
{
	t_array	ans;
	int		storage[length];
	t_stack	b[1];

	ans = NEW_ARRAY(unsigned);
	*b = STACK_NEW(storage);
	select_sort(&ans, a, b);
	return (ans);
}

int		main(int ac, char **av)
{
	int		storage[ac];
	t_stack	a[1];
	t_array	program;

	if (ac == 1 || !read_args(ac - 1, av + 1, storage))
	{
		ft_dprintf(2, "Error\n");
		return (0);
	}
	*a = STACK_NEW(storage);
	a->back = ftq_end(a) - ftq_offset(a, 1);
	program = get_instructions(ac, a);
	fta_iter(&program, &ft_putendl);
	return (0);
}
