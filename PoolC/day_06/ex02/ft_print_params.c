/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 09:26:50 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/15 09:30:46 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int ac, char **av)
{
	int k;
	int c;

	k = 0;
	while (++k < ac)
	{
		c = -1;
		while (av[k][++c])
			ft_putchar(av[k][c]);
		ft_putchar('\n');
	}
	return (0);
}
