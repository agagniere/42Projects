/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/13 09:42:21 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/14 02:11:15 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_iterative_factorial(int nb);
int		ft_recursive_factorial(int nb);
int		ft_recursive_power(int nb, int power);
int		ft_iterative_power(int nb, int power);
int		ft_fibonacci(int index);
int		ft_sqrt(int nb);
int		ft_is_prime(int nb);
int		ft_find_next_prime(int nb);
int		ft_eight_queens_puzzle(void);
int		ft_eight_queens_puzzle2(void);

int		main(int ac, char **av)
{
	int k;
	int t;
	int u;

	k = 0;
	while (++k < ac)
		switch (atoi(av[k]))
		{
		case 0 :
			if (k + 1 < ac)
				t = atoi(av[++k]);
			else
				t = 12;
			printf("Ex00 :\t(%i)! = %i\n", t, ft_iterative_factorial(t));
			break;
		case 1 :
			if (k + 1 < ac)
				t = atoi(av[++k]);
			else
				t = 12;
			printf("Ex01 :\t(%i)! = %i\n", t, ft_recursive_factorial(t));
			break;
		case 2 :
			if (k + 2 < ac) {
				t = atoi(av[++k]);
				u = atoi(av[++k]);
			} else {
				t = 3;
				u = 6;
			}
			printf("Ex02 :\t(%i)^(%i) = %i\n", t, u, ft_iterative_power(t, u));
			break;
		case 3 :
			if (k + 2 < ac) {
				t = atoi(av[++k]);
				u = atoi(av[++k]);
			} else {
				t = 3;
				u = 6;
			}
			printf("Ex03 :\t(%i)^(%i) = %i\n", t, u, ft_recursive_power(t, u));
			break;
		case 4 :
			if (k + 1 < ac)
				t = atoi(av[++k]);
			else
				t = 46;
			printf("Ex04 :\tF(%i) = %i\n", t, ft_fibonacci(t));
			break;
		case 5 :
			if (k + 1 < ac)
				t = atoi(av[++k]);
			else
				t = 144;
			printf("Ex05 :\tsqrt(%i) = %i\n", t, ft_sqrt(t));
			break;
		case 6 :
			if (k + 1 < ac)
				t = atoi(av[++k]);
			else
				t = 997;
			printf("Ex06 :\tis_prime(%i) = %i\n", t, ft_is_prime(t));
			break;
		case 7 :
			if (k + 1 < ac)
				t = atoi(av[++k]);
			else
				t = 998;
			printf("Ex07 :\tnext_prime(%i) = %i\n", t, ft_find_next_prime(t));
			break;
		case 8 :
			printf("Ex08 :\tqueens(8) = %i\n", ft_eight_queens_puzzle());
			break;
		case 9 :
			printf("Ex09 :\n");
			ft_eight_queens_puzzle2();
			break;
		}
}
