/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/09 21:52:54 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/09 22:28:08 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_putchar(char c);

void ft_print_comb(void)
{
	int		a;
	char	u;
	char	d;
	char	t;

	a = 10;
	while (++a < 800)
	{
		u = 48 + a / 100;
		d = 48 + (a % 100) / 10;
		t = 48 + a % 10;
		if (u < d && d < t)
		{
			if (a != 12)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			ft_putchar(u);
			ft_putchar(d);
			ft_putchar(t);
		}
	}
}
