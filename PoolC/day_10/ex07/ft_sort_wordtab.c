/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/21 22:39:01 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/21 23:17:11 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		my_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}

void	my_swap(char **a, char **b)
{
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
