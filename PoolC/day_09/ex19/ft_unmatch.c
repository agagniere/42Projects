/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unmatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/17 15:10:40 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/17 15:10:40 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_unmatch(int *tab, int length)
{
	int		booltab[length];
	int		ati[3];

	ati[0] = -1;
	while (++ati[0] < length)
		booltab[ati[0]] = 0;
	ati[0] = -1;
	while (++ati[0] < length)
		if (!booltab[ati[0]])
		{
			ati[1] = ati[0];
			ati[2] = 0;
			while (++ati[1] < length)
				if (!booltab[ati[1]] && tab[ati[0]] == tab[ati[1]])
				{
					booltab[ati[0]] = 1;
					booltab[ati[1]] = 1;
					++ati[2];
					break ;
				}
			if (!ati[2])
				return (tab[ati[0]]);
		}
	return (tab[length]);
}
