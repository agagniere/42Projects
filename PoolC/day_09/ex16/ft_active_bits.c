/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_active_bits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/17 12:54:40 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/17 15:14:38 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_active_bits(int value)
{
	int ans;

	ans = 0;
	while (value > 0)
	{
		ans += value % 2;
		value /= 2;
	}
	return (ans);
}
