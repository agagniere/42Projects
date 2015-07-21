/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/11 13:49:11 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/11 18:25:21 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b);

void	ft_sort_integer_table(int *tab, int size)
{
	int go_on;
	int i;

	go_on = 1;
	while (go_on)
	{
		i = 0;
		go_on = 0;
		while (++i < size)
			if (tab[i] < tab[i - 1])
			{
				go_on = 1;
				ft_swap(tab + i, tab + i - 1);
			}
	}
}
