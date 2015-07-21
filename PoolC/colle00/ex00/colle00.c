/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/11 11:18:48 by hkaddour          #+#    #+#             */
/*   Updated: 2015/07/12 20:29:54 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_putchar(char c);

void print_char(int ligne, int colonne, int x, int y)
{
	if (ligne == 0 || ligne == y - 1)
	{
		if (colonne == 0 || colonne == x - 1)
			ft_putchar('o');
		else
			ft_putchar('-');
	}
	else
	{
		if (colonne == 0 || colonne == x - 1)
			ft_putchar('|');
		else
			ft_putchar(' ');
	}
}

void colle(int x, int y)
{
	int ligne;
	int colonne;

	ligne = 0;
	while (ligne < y)
	{
		colonne = 0;
		while (colonne < x)
		{
			print_char(ligne, colonne, x, y);
			colonne++;
		}
		if (x > 0)
			ft_putchar('\n');
		ligne++;
	}
}
