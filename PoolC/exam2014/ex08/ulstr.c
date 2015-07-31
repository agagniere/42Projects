/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 18:05:56 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/31 18:11:49 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		in(char c, char min, char max)
{
	return (min <= c && c <= max);
}

void	ul(char *str)
{
	char const	*ptr = str;

	while (*str)
	{
		if (in(*str, 'a', 'z'))
			*str -= 32;
		else if (in(*str, 'A', 'Z'))
			*str += 32;
		str++;
	}
	write(1, ptr, str - ptr);
}

int		main(int ac, char **av)
{
	if (ac > 1)
		ul(av[1]);
	write(1, "\n", 1);
	return (0);
}
