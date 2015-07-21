/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/21 17:45:30 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/21 22:30:13 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super.h"

void	compute(t_myint a, t_myint b, char c)
{
	int			i;
	char const	operators[] = {'+', '-', '*', '/', '%', 0};
	t_fun const	functions[] = {&plus, &minus, &times, &divide, &modulo};

	i = 0;
	while (operators[i] && operators[i] != c)
		i++;
	if (operators[i])
	{
		if (operators[i] == '/' && b == 0)
			ft_putstr("Stop : division by 0");
		else if (operators[i] == '%' && b == 0)
			ft_putstr("Stop : modulo by 0");
		else
			ft_putnbr(functions[i](a, b));
	}
	else
		ft_putchar('0');
}
