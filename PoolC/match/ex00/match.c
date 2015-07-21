/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/18 14:11:56 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/19 23:42:40 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		match(char *s1, char *s2)
{
	if (*s2 == '*')
	{
		if (*s1 != 0)
			return (match(s1 + 1, s2) || match(s1, s2 + 1));
		else
			return (match(s1, s2 + 1));
	}
	if (*s1 == *s2)
	{
		if (*s1 != 0)
			return (match(s1 + 1, s2 + 1));
		else
			return (1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	printf("%i", match("bonsoir", "bonsoir***"));
}
