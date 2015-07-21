/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 09:21:59 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/15 09:25:46 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int ac, char **av)
{
	int k;

	k = -1;
	(void)ac;
	while (av[0][++k])
		ft_putchar(av[0][k]);
	ft_putchar('\n');
	return (0);
}
