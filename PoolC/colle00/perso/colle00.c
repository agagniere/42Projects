/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/12 12:37:56 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/12 14:32:58 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	colle(int x, int y)
{
	int		ligne;
	int		colonne;

	ligne = 0;
	while (++ligne <= y)
	{
		colonne = 0;
		while (++colonne <= x)
			if (ligne == 1 || ligne == y)
			{
				if (colonne == 1 || colonne == x)
					ft_putchar('o');
				else
					ft_putchar('-');
			}
			else
			{
				if (colonne == 1 || colonne == x)
					ft_putchar('|');
				else
					ft_putchar(' ');
			}
		ft_putchar('\n');
	}
}
