/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/17 07:06:56 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/17 07:06:57 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_to_lowercase(char *str)
{
	int a;

	a = -1;
	while (str[++a])
	{
		if (str[a] >= 'A' && str[a] <= 'Z')
			str[a] += ('a' - 'A');
	}
	return (str);
}

int		match_ignore_spaces(char *str1, char *str2)
{
	if (*str1 == ' ')
		return (match_ignore_spaces(str1 + 1, str2));
	if (*str2 == ' ')
		return (match_ignore_spaces(str1, str2 + 1));
	if (*str1 == 0 && *str2 == 0)
		return (1);
	if (*str1 == *str2)
		return (match_ignore_spaces(str1 + 1, str2 + 1));
	return (0);
}

int		is_interesting(char *str)
{
	char	*one[3];
	int		a;

	one[0] = "president";
	one[1] = " attack  ";
	one[2] = " powers  ";
	a = -1;
	str = ft_to_lowercase(str);
	while (++a < 3)
		if (match_ignore_spaces(str, one[a]))
			return (1);
	return (0);
}

int		main(int argc, char **argv)
{
	int a;

	if (argc == 1)
		return (0);
	a = -1;
	while (++a < argc)
		if (is_interesting(argv[a]))
		{
			write(1, "Alert!!!\n", 9);
			break ;
		}
	return (0);
}
