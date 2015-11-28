/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:54:23 by angagnie          #+#    #+#             */
/*   Updated: 2015/11/28 09:36:07 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbrfd_aux(int n, int fd)
{
	if (n < -9 || 9 < n)
		ft_putnbrfd_aux(n / 10, fd);
	ft_putchar_fd('0' + ABS(n % 10), fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	ft_putnbrfd_aux(n);
}
