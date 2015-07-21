/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/16 18:28:56 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/16 18:35:20 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
void	ft_generic(void);
void	ft_takes_place(int hour);

int		main(int ac, char **av)
{
	int k;
	int i;

	k = 0;
	while (++k < ac)
		switch (atoi(av[k]))
		{
		case 0 :
			ft_generic();
			break ;
		case 1 :
			i = -1;
			while (++i < 25)
				ft_takes_place(i);
			break ;
		}
	return (0);
}
