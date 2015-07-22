/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/21 17:45:30 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/22 10:47:09 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super.h"
#include "ft_opp.h"

int		my_strcmp(t_string s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}

void	compute(t_myint a, t_myint b, t_string c)
{
	int		i;

	i = 0;
	while (gl_opptab[i].symbol[0]
		&& my_strcmp(gl_opptab[i].symbol, c))
		i++;
	ft_putstr(gl_opptab[i].function(a, b));
	ft_putchar('\n');
}
