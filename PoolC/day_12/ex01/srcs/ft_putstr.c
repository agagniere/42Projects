/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 15:28:56 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/23 16:50:53 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super.h"

void	ft_putstr_fd(int fd, char *str)
{
	char *ptr;

	ptr = str;
	while (*ptr != '\0')
		++ptr;
	write(fd, str, ptr - str);
}
