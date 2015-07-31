/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_first_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 18:02:18 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/31 18:04:41 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	char const	*ptr = str;

	while (*str)
		str++;
	write(1, ptr, str - ptr);
}

int		main(int ac, char **av)
{
	if (ac > 1)
		ft_putstr(av[1]);
	write(1, "\n", 1);
}
