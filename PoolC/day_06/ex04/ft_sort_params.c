/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 09:38:35 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/16 08:53:48 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		my_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}

void	my_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
	ft_putchar('\n');
}

void	my_swap(char **a, char **b)
{
	char *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int		main(int ac, char **av)
{
	int go_on;
	int ind;

	go_on = 1;
	while (go_on)
	{
		go_on = 0;
		ind = 1;
		while (++ind < ac)
			if (my_strcmp(av[ind - 1], av[ind]) > 0)
			{
				go_on = 1;
				my_swap(av + ind - 1, av + ind);
			}
	}
	ind = 0;
	while (++ind < ac)
		my_putstr(av[ind]);
}
