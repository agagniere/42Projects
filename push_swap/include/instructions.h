/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 17:09:18 by angagnie          #+#    #+#             */
/*   Updated: 2018/12/11 21:11:53 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTIONS_H
# define INSTRUCTIONS_H

# include "ft_stack.h"

typedef void	(*t_cmd)(t_stack *a, t_stack *b);

void			cmd_sa(t_stack *a, t_stack *b);
void			cmd_sb(t_stack *a, t_stack *b);
void			cmd_ss(t_stack *a, t_stack *b);

void			cmd_pa(t_stack *a, t_stack *b);
void			cmd_pb(t_stack *a, t_stack *b);

void			cmd_ra(t_stack *a, t_stack *b);
void			cmd_rb(t_stack *a, t_stack *b);
void			cmd_rr(t_stack *a, t_stack *b);

void			cmd_rra(t_stack *a, t_stack *b);
void			cmd_rrb(t_stack *a, t_stack *b);
void			cmd_rrr(t_stack *a, t_stack *b);

bool			execute_instruction(const char *instruction,
									t_stack *a, t_stack *b);

#endif
