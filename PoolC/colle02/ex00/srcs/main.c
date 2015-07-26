/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 15:04:20 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/26 20:37:13 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "super.h"

int		main(void)
{
	char	**tab;
	t_coord	*dimensions;

	if (!(dimensions = ft_read_stdin(&tab)))
	{
		ft_putstr("aucune\n");
		return (0);
	}
	db_printint("Line number", dimensions->y);
	db_printint("Line length", dimensions->x);
	gooo(tab, dimensions);
	return (0);
}
