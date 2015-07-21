/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/10 11:59:55 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/10 22:51:17 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_print_combn(int n)
{
	char	c[9];
	int		a;

	a = -1;
	while (++a < 9)
		c[a] = - 1;
	aux(1, -1, n, c);
}

int		min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	print(char c[9], int total)
{
	int a;

	a = -1;
	while (++a < total)
			ft_putchar(48 + c[a]);
	if (c[a - 1] != total)
}

void	aux(int rank, int greatest, int total, char str[9])
{
	if (rank == total)
	{
		str[rank - 1] = 
	}
}
