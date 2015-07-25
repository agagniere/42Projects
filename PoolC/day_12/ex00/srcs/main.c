/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 15:04:20 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/23 16:53:51 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super.h"

int		main(int ac, char **av)
{
	if (ac == 1)
	{
		ft_putstr_fd(STD_ERR, "File name missing.\n");
	}
	else if (ac > 2)
	{
		ft_putstr_fd(STD_ERR, "Too many arguments.\n");
	}
	else
	{
		ft_display_file(av[1]);
	}
	return (0);
}
