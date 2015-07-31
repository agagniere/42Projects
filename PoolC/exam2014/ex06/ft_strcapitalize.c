/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 17:47:59 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/31 18:01:27 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		in(char c, char min, char max)
{
	return (min <= c && c <= max);
}

void	cap(char *str)
{
	int		was_an;
	char	*ptr;

	was_an = 0;
	ptr = str;
	while (*ptr)
	{
		if (in(*ptr, 'A', 'Z') && was_an)
			*ptr += 32;
		else if (in(*ptr, 'a', 'z') && !was_an)
			*ptr -= 32;
		was_an = in(*ptr, '0', '9') || in(*ptr, 'a', 'z')
			|| in(*ptr, 'A', 'Z');
		ptr++;
	}
	write(1, str, ptr - str);
}

int		main(int ac, char **av)
{
	if (ac > 1)
		cap(av[1]);
	write(1, "\n", 1);
	return (0);
}
