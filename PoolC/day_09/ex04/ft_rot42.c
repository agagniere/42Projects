/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot42.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/16 21:50:45 by angagnie          #+#    #+#             */
/*   Updated: 2015/07/16 21:50:47 by angagnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_upcase(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= 'a' && c <= 'z')
		return (2);
	return (0);
}

char	*ft_rot42(char *str)
{
	int		a;
	char	c;

	a = -1;
	while (str[++a])
	{
		if (is_upcase(str[a]) == 0)
			continue ;
		if (is_upcase(str[a]) == 1)
			c = 'A';
		if (is_upcase(str[a]) == 2)
			c = 'a';
		str[a] = (str[a] - c + 42) % 26 + c;
	}
	return (str);
}
