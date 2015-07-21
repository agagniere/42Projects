/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkaddour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/11 11:18:48 by hkaddour          #+#    #+#             */
/*   Updated: 2015/07/12 21:23:06 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_putchar(char c);

void print_char01(int ligne, int colonne, int x, int y)
{
	if (ligne == 0 && colonne == 0)
		ft_putchar('/');
	else if ((ligne == y - 1 && colonne == 0)
		|| (ligne == 0 && colonne == x - 1))
		ft_putchar('\\');
	else if (ligne == y - 1 && colonne == x - 1)
		ft_putchar('/');
	else if (ligne == 0 || colonne == 0 || ligne == y - 1 || colonne == x - 1)
		ft_putchar('*');
	else
		ft_putchar(' ');
}
