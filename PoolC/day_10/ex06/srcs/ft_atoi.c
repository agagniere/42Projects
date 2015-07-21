/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/21 15:47:42 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/21 21:11:59 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super.h"

t_myint		ft_atoi(char *str)
{
	t_uint	i;
	int		sign;
	t_myint	ans;

	i = 0;
	while (str[i] == ' ')
		++i;
	sign = (str[i] == '-' ? -1 : 1);
	i += (str[i] == '-' || str[i] == '+' ? 1 : 0);
	ans = 0;
	while (47 < str[i] && str[i] < 58)
		ans = 10 * ans + str[i++] - 48;
	return (ans * sign);
}
