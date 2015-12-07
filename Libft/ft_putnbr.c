/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:54:23 by angagnie          #+#    #+#             */
/*   Updated: 2015/12/07 18:13:52 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** |void	ft_putnbr_aux(int n)
** |{
** |	if (n < -9 || 9 < n)
** |		ft_putnbr_aux(n / 10);
** |	ft_putchar('0' + ABS(n % 10));
** |}
** |
** |void	ft_putnbr(int n)
** |{
** |	if (n < 0)
** |		ft_putchar('-');
** |	ft_putnbr_aux(n);
** |}
*/

void	ft_putnbr(int n)
{
	ft_putstr(ft_itoa_base(n, 10));
}
