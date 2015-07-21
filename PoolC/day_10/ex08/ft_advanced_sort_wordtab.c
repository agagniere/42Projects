/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/21 22:39:01 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/21 23:31:12 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	my_swap(char **a, char **b)
{
	char *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	t_sort_wordtab(char **tab)
{
	int		done;
	int		i;

	done = 0;
	while (!done)
	{
		done = 1;
		i = 0;
		while (tab[++i])
			if (my_strmp(tab[i - 1], tab[i]) > 0)
			{
				my_swap(tab + i - 1, tab + i);
				done = 0;
			}
	}
}
