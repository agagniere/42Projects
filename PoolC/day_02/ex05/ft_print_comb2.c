/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/09 22:30:33 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/09 22:35:53 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_putchar(char c);

void ft_print_comb2(void)
{
	int		a;
	char	u;
	char	d;

	a = 0;
	while (++a < 10000)
	{
		u = a / 100;
		d = a % 100;
		if (u < d)
		{
			if (a != 1)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			ft_putchar(48 + u / 10);
			ft_putchar(48 + u % 10);
			ft_putchar(' ');
			ft_putchar(48 + d / 10);
			ft_putchar(48 + d % 10);
		}
	}
}
