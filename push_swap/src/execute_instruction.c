/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@sudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:55:59 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/11 21:13:25 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
#include "ft_stack.h"
#include "ft_prepro.h"
#include "libft.h"
#include "instructions.h"

#include <stdbool.h>

bool	execute_instruction(const char *instruction, t_stack *a, t_stack *b)
{
	unsigned	n;
	const char	cmd[][4] = {
		"ra", "rb", "rr", "rra", "rrb", "rrr",
		"sa", "sb", "ss", "pa", "pb"};
	const t_cmd	t[] = {
		cmd_ra, cmd_rb, cmd_rr, cmd_rra, cmd_rrb, cmd_rrr,
		cmd_sa, cmd_sb, cmd_ss, cmd_pa, cmd_pb};

	n = (instruction[0] == 'r' ? 0 : 6);
	while (n < ARRAY_LENGTH(t) && ft_strcmp(cmd[n], instruction))
		n++;
	if (n < ARRAY_LENGTH(t))
		t[n](a, b);
	return (n < ARRAY_LENGTH(t));
}
