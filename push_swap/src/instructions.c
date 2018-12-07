/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:18:41 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/07 17:37:29 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instructions.h"

void	cmd_sa(t_stack *a, t_stack *b)
{
	(void)b;
	stack_swap(a);
}

void	cmd_sb(t_stack *a, t_stack *b)
{
	(void)a;
	stack_swap(b);
}

void	cmd_ss(t_stack *a, t_stack *b)
{
	stack_swap(a);
	stack_swap(b);
}

void	cmd_pa(t_stack *a, t_stack *b)
{
	int		tmp[1];

	stack_pop(b, tmp);
	stack_push(a, tmp);
}

void	cmd_pb(t_stack *a, t_stack *b)
{
	cmd_pa(b, a);
}

void	cmd_ra(t_stack *a, t_stack *b)
{
	(void)b;
	stack_rotate(a);
}

void	cmd_rb(t_stack *a, t_stack *b)
{
	(void)a;
	stack_rotate(b);
}

void	cmd_rr(t_stack *a, t_stack *b)
{
	stack_rotate(a);
	stack_rotate(b);
}

void	cmd_rra(t_stack *a, t_stack *b)
{
	(void)b;
	stack_rotate_reverse(a);
}

void	cmd_rrb(t_stack *a, t_stack *b)
{
	(void)a;
	stack_rotate_reverse(b);
}

void	cmd_rrr(t_stack *a, t_stack *b)
{
	stack_rotate_reverse(a);
	stack_rotate_reverse(b);
}
