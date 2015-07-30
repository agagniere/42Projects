/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 02:02:43 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/30 17:23:17 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super.h"

void	malloc_fail(void)
{
	write(2, "Malloc Failed\n", 14);
	exit(0);
}

t_int	max(t_int a, t_int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

t_int	min(t_int tmp[3])
{
	if (tmp[0] <= tmp[1] && tmp[0] <= tmp[2])
		return (tmp[0]);
	else if (tmp[1] <= tmp[0] && tmp[1] <= tmp[2])
		return (tmp[1]);
	else if (tmp[2] <= tmp[0] && tmp[2] <= tmp[1])
		return (tmp[2]);
	db_print_str("(min)", "WTF !!");
	return (0);
}
