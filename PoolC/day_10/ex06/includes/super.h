/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/21 16:10:58 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/21 22:34:47 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPER_H
# define SUPER_H

# include <unistd.h>
# define ERROR -27315

typedef long long int	t_myint;
typedef unsigned int	t_uint;
typedef t_myint			(*t_fun)(t_myint, t_myint);

t_myint	ft_atoi(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(t_myint n);
void	compute(t_myint a, t_myint b, char c);

t_myint	plus(t_myint a, t_myint b);
t_myint	minus(t_myint a, t_myint b);
t_myint	times(t_myint a, t_myint b);
t_myint	divide(t_myint a, t_myint b);
t_myint	modulo(t_myint a, t_myint b);

#endif
