/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/22 15:02:22 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/23 21:27:32 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int ac, char **av)
{
	t_str	str1, str2;
	int		k, i, j;
	t_list	*tmp;

	k = 0;
	//printf("Note : your Ex06 is used for each test.\n");
	while (k < (ac == 1 ? K_MAX + 1 : ac - 1))
		switch (ac == 1 ? k++ : atoi(av[++k]))
		{
		case 0 :
			if (k + 1 < ac)
				str1 = av[++k];
			else
				str1 = strdup("Foo Bar Baz");
			printf("Ex 00 : expected [| %s |] :\t%s", str1, GREEN);
			ft_print_list_str(ft_create_elem(str1));
			printf("%s\n", END);
			break ;
		case 1 :
			if (k + 1 < ac)
				str1 = av[++k];
			else
				str1 = strdup("Hello");
			if (k + 1 < ac)
				str2 = av[++k];
			else
				str2 = strdup("World");
			tmp = ft_create_elem(str1);
			printf("Ex 01 :\n\t- expected [| %s ; %s ; %s |] (normal push back)\n\t\t%s", str1, str2, str2, GREEN);
			ft_list_push_back(&tmp, str2);
			ft_list_push_back(&tmp, str2);
			ft_print_list_str(tmp);
			printf("%s\t- expected [| %s ; %s |] (push back on an empty list)\n\t\t%s", END, str1, str2, GREEN);
			tmp = NULL;
			ft_list_push_back(&tmp, str1);
			ft_list_push_back(&tmp, str2);
			ft_print_list_str(tmp);
			printf("%s\n", END);
			break ;
		case 2 :			
			if (k + 1 < ac)
				str1 = av[++k];
			else
				str1 = strdup("Caesar");
			if (k + 1 < ac)
				str2 = av[++k];
			else
				str2 = strdup("Ave");
			tmp = ft_create_elem(str1);
			printf("Ex 02 :\n\t- expected [| %s ; %s ; %s |] (normal push front)\n\t\t%s", str1, str2, str2, GREEN);
			ft_list_push_front(&tmp, str2);
			ft_list_push_front(&tmp, str2);
			ft_print_list_str(tmp);
			printf("%s\t- expected [| %s ; %s |] (push front on an empty list)\n\t\t%s", END, str1, str2, GREEN);
			tmp = NULL;
			ft_list_push_front(&tmp, str1);
			ft_list_push_front(&tmp, str2);
			ft_print_list_str(tmp);
			printf("%s\n", END);
			break ;
		case 3 :
			if (k + 1 < ac)
			{
				i = atoi(av[++k]);
				i *= (i < 0 ? -1 : 1);
			}
			else
				i = 13;
			j = -1;
			tmp = NULL;
			str1 = strdup("Tralala");
			while (++j < i)
				ft_list_push_front(&tmp, str1);
			j = ft_list_size(tmp);
			if (j == i)
				printf("%s[Ex03 OK]%s\t(tested on a list of %i elements)\n", GREEN, END, i);
			else
				printf("%s>>>[Ex03 FAIL]<<<%s\t(a list of %i elements is not %i element long)\n", RED, END, i, j);
			break ;
		case 4 :
			str1 = strdup("\e[1;31m>>>[Ex04 FAIL]<<<\e[0;0m");
			str2 = strdup("\e[1;32m[Ex04 OK]\e[0;0m");
			tmp = NULL;
			i = -1;
			ft_list_push_front(&tmp, str2);
			while (++i < 50)
				ft_list_push_front(&tmp, str1);
			printf("%s\t(tested on a list of 50 elements)\n", (char*)ft_list_last(tmp)->data);
			break ;
		case 5 :
			printf("Ex05 : You should see the arguments you passed in a reversed order :\n\t%s", GREEN);
			ft_print_list_str(ft_list_push_params(ac, av));
			printf("%s\n", END);
			break ;
		case 6 :
			i = 13;
			j = -1;
			tmp = NULL;
			ft_list_push_back(&tmp, str1);
			str1 = strdup("Tralala");
			while (++j < i)
				ft_list_push_front(&tmp, str1);
			ft_list_clear(&tmp);
			j = ft_list_size(tmp);
			if (j == 0)
				printf("%s[Ex06 OK]%s\n", GREEN, END);
			else
				printf("%s>>>[Ex06 FAIL]<<<%s\n", RED, END);
			break ;
		case 7 :
			
			break ;
		}
}
