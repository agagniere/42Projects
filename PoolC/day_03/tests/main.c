/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/10 09:29:15 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/11 13:39:11 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
char	*ft_strrev(char *str);

int		main(int ac, char **av)
{
	printf("Ex05 :\t");
	ft_putstr(av[0]);
	printf("\n");
	if (ac == 2)
	{
		printf("Ex06 :\n\tPour '%s' :\t%i\n\tPour '%s' :\t%i\n", av[0], ft_strlen(av[0]), av[1], ft_strlen(av[1]));
		printf("Ex07 :\t'%s'\n", ft_strrev(av[1]));
		printf("Ex08 :\t%i\n", ft_atoi(av[1]));
	}
	return (0);
}
