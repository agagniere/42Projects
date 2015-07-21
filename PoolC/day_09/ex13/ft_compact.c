/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compact.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/17 07:14:10 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/17 07:19:05 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_compact(char **tab, int length)
{
	int		a;
	int		nbr_mdf;

	a = -1;
	nbr_mdf = 0;
	while (++a < length)
	{
		if (tab[a][0] && nbr_mdf)
			tab[a - nbr_mdf] = tab[a];
		else
			++nbr_mdf;
	}
	return (length - nbr_mdf);
}
