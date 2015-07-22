/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/22 09:50:18 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/22 10:27:49 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

typedef long long int			t_myint;
typedef unsigned int			t_uint;
typedef char					*t_string;
typedef t_string				(*t_fun)(t_myint, t_myint);
typedef enum					e_bool
{
	TRUE,
	FALSE
}								t_bool;
typedef struct					s_opp
{
	t_string	symbol;
	t_fun		function;
}								t_opp;

t_myint							ft_atoi(char *str);
t_string						ft_itoa_base(t_myint value, int base);
t_string						ft_itoa(t_myint value);
void							ft_putchar(char c);
void							ft_putstr(char *str);
void							ft_putnbr(t_myint n);
void							compute(t_myint a, t_myint b, t_string c);

t_string						ft_add(t_myint a, t_myint b);
t_string						ft_sub(t_myint a, t_myint b);
t_string						ft_mul(t_myint a, t_myint b);
t_string						ft_div(t_myint a, t_myint b);
t_string						ft_mod(t_myint a, t_myint b);
t_string						ft_pow(t_myint a, t_myint b);
t_string						ft_usage(t_myint a, t_myint b);

#endif
