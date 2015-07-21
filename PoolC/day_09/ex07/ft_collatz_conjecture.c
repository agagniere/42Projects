/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collatz_conjecture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/17 07:06:40 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/17 07:06:44 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int ft_collatz_conjecture(unsigned int base)
{
	if (base == 1)
		return (0);
	if (base % 2)
		return (1 + ft_collatz_conjecture(base * 3 + 1));
	return (1 + ft_collatz_conjecture(base / 2));
}
