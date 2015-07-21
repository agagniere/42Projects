/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmatch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/19 23:03:25 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/19 23:19:18 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		aux(char *s1, char *s2)
{
	if (*s2 == '*')
	{
		if (*s1 != 0)
			return (aux(s1 + 1, s2) + aux(s1, s2 + 1));
		else
			return (aux(s1, s2 + 1));
	}
	if (*s1 == *s2)
	{
		if (*s1 != 0)
			return (aux(s1 + 1, s2 + 1));
		else
			return (1);
	}
	return (0);
}

int		nmatch(char *s1, char *s2)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	return (aux(s1, s2));
}

int		main(int ac, char **av)
{
	if (ac == 3)
		printf("%i\n", nmatch(av[1], av[2]));
	return (0);
}
