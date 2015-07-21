/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/17 13:11:43 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/17 15:20:59 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_join(char **tab, char *sep)
{
	int		abct[4];
	char	*rep;

	abct[2] = -1;
	abct[3] = 0;
	while (sep[++abct[2]])
		;
	abct[0] = -1;
	while (tab[++abct[0]])
	{
		abct[1] = -1;
		while (tab[abct[0]][++abct[1]])
			++abct[3];
	}
	rep = (char *)malloc(sizeof(char) * (abct[3] + abct[0] * abct[2]));
	if (!rep)
		return (NULL);
	abct[0] = -1;
	abct[3] = -1;
	while (tab[++abct[0]])
	{
		abct[1] = -1;
		while (tab[abct[0]][++abct[1]])
			rep[++abct[3]] = tab[abct[0]][abct[1]];
		abct[1] = -1;
		while (sep[++abct[1]])
			rep[++abct[3]] = sep[abct[1]];
	}
	return (rep);
}
