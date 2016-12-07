/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 19:15:32 by angagnie          #+#    #+#             */
/*   Updated: 2016/12/08 00:00:49 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

int		main(int ac, char **av)
{
	char const	*s = "(%hhi,%X,%s,%-20s)\n";

	(void)ac;
	(void)av;
	printf(s, 200, 0xDEADBEEF, "Real Printf", "Helloλ\0");
	ft_printf(s, 200, 0xDEADBEEF, "My   Printf", "Helloλ\0");
	return (0);
}
