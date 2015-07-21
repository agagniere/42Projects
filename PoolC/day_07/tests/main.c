/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/16 11:07:17 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/17 23:01:07 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(char *src);
int		*ft_range(int min, int max);
int		ft_ultimate_range(int **range, int min, int max);
char	*ft_concat_params(int argc, char **argv);

void	print_tab(int *tab, int length)
{
	int k = -1;

	printf(" --== Tab ==--\n");
	while (++k < length)
		printf("tab[%i] =\t%i\n", k, tab[k]);
	printf(" ---=======---\n\n");
}

int		main(int ac, char **av)
{
	int k = 0, a, b;
	char	*str;
	int		*tab;

	while (++k < ac)
		switch (atoi(av[k]))
		{
		case 0 :
			if (k + 1 < ac)
				str = av[++k];
			else
				str = "Hello Bitches !";
			printf("Ex00 : \"%s\"->\"%s\"\n", str, ft_strdup(str));
			break ;
		case 1 :
			if (k + 2 < ac)
			{
				a = atoi(av[++k]);
				b = atoi(av[++k]);
			}
			else
			{
				a = -4;
				b = 3;
			}
			print_tab(ft_range(a, b), b - a);
			break ;
		case 2 :
			tab = (int *)malloc(200);
			if (k + 2 < ac)
			{
				a = atoi(av[++k]);
				b = atoi(av[++k]);
			}
			else
			{
				a = -4;
				b = 3;
			}
			ft_ultimate_range(&tab, a, b);
			print_tab(tab, ft_ultimate_range(&tab, a, b));
			break ;
		}
	return (0);
}
