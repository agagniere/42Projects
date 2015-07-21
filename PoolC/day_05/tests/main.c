/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/14 16:22:23 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/15 22:39:11 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strcpy(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strstr(char *str, char *to_find);
void	ft_putnbr_base(int nbr, char *base);
char	*ft_strupcase(char *str);
char	*ft_strlowcase(char *str);
char	*ft_strcapitalize(char *str);

int		main(int ac, char **av)
{
	int		k = 0,
			i;
	char	*str,
			*dst;

	while (++k < ac)
		switch (atoi(av[k]))
		{
		case 0 :
			if (k + 1 < ac)
				str = av[++k];
			else
				str = "Hello World !";
			dst = (char *)malloc(100);
			printf("Ex00 :\t\"%s\" = \"%s\"\n", str, ft_strcpy(dst, str));
			break ;
		case 1 :
			if (k + 1 < ac)
			{
				str = av[++k];
				if (k + 1 < ac)
					i = atoi(av[++k]);
				else
					i = 5;
			}
			else
			{
				str = "Hello World !";
				i = 5;
			}
			dst = (char *)malloc(100);
			printf("Ex01 :\t(\"%s\", %i) = \"%s\"\n", str, i, ft_strncpy(dst, str, i));
			break ;
		case 2 :			
			if (k + 1 < ac)
			{
				str = av[++k];
				if (k + 1 < ac)
					dst = av[++k];
				else
					dst = "Can";
			}
			else
			{
				str = "Cave Canem";
				dst = "Can";
			}
			printf("Ex02 :\t(\"%s\", \"%s\") = \"%s\"\n", str, dst, ft_strstr(str, dst));
			break ;
		case 5 :
			if (k + 1 < ac)
				str = av[++k];
			else
				str = "Hello World !";
			printf("Ex05 :\t%s -> %s\n", str, ft_strupcase(str));
			break ;
		case 6 :
			if (k + 1 < ac)
				str = av[++k];
			else
				str = "Hello World !";
			printf("Ex06 :\t%s -> %s\n", str, ft_strlowcase(str));
			break ;
		case 7 :
			if (k + 1 < ac)
				str = av[++k];
			else
				str = "Hello World !";
			printf("Ex07 :\t%s -> %s\n", str, ft_strcapitalize(str));
			break ;
		case 17 :
			if (k + 1 < ac)
			{
				i = atoi(av[++k]);
				if (k + 1 < ac)
					str = av[++k];
				else
					str = "0123456789ABCDEF";
			}
			else
			{
				i = 11;
				str = "01";
			}
			printf("Ex17 :\t%i en base \"%s\" : ", i, str);
			ft_putnbr_base(i, str);
			printf("\n");
			break ;
		}
	return (0);
}
