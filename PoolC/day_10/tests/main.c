/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/21 12:44:08 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/21 23:08:49 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define END "\033[1;0m"

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_foreach(int *tab, int length, void (*f)(int));
int		*ft_map(int *map, int length, int (*f)(int));
int		ft_any(char **tab, int (*f)(char *));
int		ft_count_if(char **tab, int (*f)(char *));
int		ft_is_sort(int *tab, int length, int (*f)(int, int));

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(48 + n % 10);
}

int		ft_abs_half(int i)
{
	i = (i < 0 ? -i : i);
	return (i >> 1);
}

int		isupcase(char *str)
{
	if (!*str)
		return (1);
	return ('A' <= *str && *str <= 'Z' ? isupcase(str + 1) : 0);
}

void	ft_print(char *str, char *color)
{
	printf("%s%s%s\n", color, str, END);
}

int		cmp(int a, int b)
{
	return (b - a);
}

int		main(int ac, char **av)
{
	int		k;
	int		pi[] = {14, 15, 92, 65, 35, 89, 79, 32, 38, 46, 26, 43, 38, 32, 79, 50};
	int		tab[] = {10, 20, 30, 40};
	char	*words1[] = {"Hello", "World", "RTFM", "LMGIFY", "GIYF", "NSFW", 0};
	char	*words2[] = {"O miseras", "homini", "mentis", "O pectora", "caeca", 0};

	k = -1;
	while (++k < (ac == 1 ? 6 : ac))
		switch (ac == 1 ? k : atoi(av[k]))
		{
		case 1 :
			ft_putstr("Ex01 : Pi = 3,");
			ft_putstr(GREEN);
			ft_foreach(pi, 16, &ft_putnbr);
			ft_putstr(END);
			ft_putstr("...\n");
			break ;
		case 2 :
			ft_putstr("Ex02 : Expected \"5101520\" : \"");
			ft_foreach(ft_map(tab, 4, &ft_abs_half), 4, &ft_putnbr);
			ft_putstr("\"\n");
			break ;
		case 3 :
			if (ft_any(words1, &isupcase) && !ft_any(words2, &isupcase))
				ft_print("[Ex03 OK]", GREEN);
			else
				ft_print(">>>[Ex03 FAIL]<<<", RED);
			break ;
		case 4 :
			if (ft_count_if(words1, &isupcase) == 4 && !ft_count_if(words2, &isupcase))
				ft_print("[Ex04 OK]", GREEN);
			else
				ft_print(">>>[Ex04 FAIL]<<<", RED);
			break ;
		case 5 :
			if (ft_is_sort(tab, 4, &cmp) && !ft_is_sort(pi, 16, &cmp))
				ft_print("[Ex05 OK]", GREEN);
			else
				ft_print(">>>[Ex06 FAIL]<<<", RED);
			break ;
		case 7 :
			
			break ;
		}
	return (0);
}
